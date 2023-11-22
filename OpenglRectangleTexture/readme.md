# 纹理（知识点）
**以下是纹理用到的知识点，至于具体流程操作请参考：**
[https://learnopengl.com/Getting-started/Textures](https://learnopengl.com/Getting-started/Textures)
## 纹理环绕
纹理环绕（Texture Wrapping）的作用是定义在纹理坐标超出标准范围时系统如何处理。纹理坐标通常在[0, 1]范围内，表示纹理图像上的相对位置。当纹理坐标超出这个范围时，纹理包裹规定了采取的行为，以防止纹理映射时出现问题。

以下是纹理环绕的主要作用：

1. **处理纹理坐标超出标准范围：** 纹理包裹确保纹理坐标在 [0, 1] 范围内，防止超出范围导致的问题。这包括避免纹理的重复、拉伸、挤压或其他不自然的效果。

2. **提供更自然的纹理映射：** 在图形渲染中，使用纹理包裹可以确保纹理在几何表面上的映射看起来更加自然和符合预期。选择适当的包裹模式有助于消除视觉上的不连续性和不规则性。

常见的纹理包裹模式包括：

- **重复（GL_REPEAT）：** 超出[0, 1]范围的坐标会被截断，将其取小数部分，使其重新回到[0, 1]范围。适用于需要纹理在几何图形表面上多次重复的情况，如地板、墙壁等。

- **镜像重复（GL_MIRRORED_REPEAT）：** 类似于重复，但在超出范围时进行镜像反转。适用于需要纹理在重复的同时进行反转的情况，有时可以提供更平滑的过渡。

- **夹取到边缘（GL_CLAMP_TO_EDGE）：** 超出范围的坐标会被夹取到0.0或1.0，即被强制限制在[0, 1]范围内。适用于需要防止纹理在边缘拉伸的情况，如绘制平铺的地板。

- **夹取到边缘，但在超出范围时进行插值（GL_CLAMP_TO_BORDER）：** 超出范围的坐标会被夹取到一个指定的边界颜色。适用于需要在超出范围时保持纹理边缘的颜色，以模拟纹理的边缘效果。

```cpp
void glTexParameteri(GLenum target, GLenum pname, GLint param);

是OpenGL中用于设置纹理参数的函数。这个函数允许你指定纹理对象的一些属性，如纹理过滤、纹理环绕等
```

- `target:`  参数指定了目标纹理，可以是 GL_TEXTURE_1D、GL_TEXTURE_2D、- GL_TEXTURE_3D 等。

- `pname:` 参数指定了你要设置的纹理参数的名称，比如纹理过滤参数、纹理环绕参数等。

- `param` 参数指定了你要设置的参数值。

```cpp
    // 设置纹理过滤参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // 设置纹理环绕参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
```


## 纹理过滤

        纹理过滤（Texture Filtering）是指在纹理映射到图形对象表面时，系统如何根据纹理坐标对纹理进行采样的过程。纹理过滤的作用是消除或减轻因纹理像素与渲染像素之间坐标不匹配而产生的锯齿状或失真等视觉问题。

        总结： 消除或减轻因纹理像素与渲染像素之间坐标不匹配而产生的锯齿状或失真等视觉问题
### 解决办法：
**`纹理过滤有多种方式，其中最常见的是点过滤和线性过滤。`**
1. **点过滤:**
- 点过滤是最简单的过滤方式，它会直接选取最接近纹理坐标的一个纹理像素的颜色。
- 适用于放大纹理，但在缩小纹理时可能产生锯齿状的效果。
2. **线性过滤:**
- 线性过滤考虑附近四个纹理像素的颜色，通过加权平均的方式进行插值。
- 在放大和缩小纹理时都相对较好地保持了图像的平滑过渡，减少了锯齿状效果

**总结：**
    
    在纹理缩小时使用最近邻过滤，并在放大纹理时使用线性过滤

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
## 生成和加载纹理
### 生成纹理
```cpp
    // 创建纹理对象
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // 纹理环绕
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // 纹理过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 转换数据
    int width, height, nrChannels;
    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
```
### 加载纹理

    其实就和 顶点数据以及颜色加载一样。

    解析坐标里面的纹理坐标，复制到VBO, 然后通过glVertexAttribPointer 解析纹理属性。利用glEnableVertexAttribArray 将数据和 顶点着色器关联。顶点着色器的输出作为片段着色器的输入（FragColor = texture(ourTexture, TexCoord);）


## 注意点：
    纹理单元: 使用一个纹理的时候，纹理单元默认是 0 ， 这个时候不用刻意去设置纹理单元， 但是当纹理单元数量超过1个的时候，就要设置。 单元默认是 0 - 128  所以不同的纹理绑定不同的纹理单元





