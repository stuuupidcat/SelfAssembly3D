# SelfAssembly3D

这是一个3D自我组装系统的demo，是论文[Massive Self-Assembly in Grid Environments](https://arxiv.org/abs/2102.05037)的简易推论和简陋实现。

## 编译环境
Windows + CMake + GCC 8.10 x86_64-w64-mingw32

## 使用方法
`./build/SelfAssembly 输入文件 输出文件`

## 输入文件格式
grid_size_x grid_size_y grid_size_z agent_num
输入的0、1矩阵
> 输入矩阵的坐标轴在方向在文件`grid.h`中有说明。

## 输出文件
为了查看结果，我将`coordinator.cpp`中的`simulate`函数部分内容注释掉了。若要查看完整的时间戳、格子状态、智能体周围光源、智能体动作，请将上述函数中注释的代码部分前的“\\\\”删除。

