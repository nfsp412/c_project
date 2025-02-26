#cmake最低版本需求，不加入此行会受到警告信息，输入下载安装的cmake版本。
cmake_minimum_required(VERSION 3.31.4)
#项目名称,即生成的.exe文件名称,这里的文件名称必需与launch.json的参数"program"的一致。
#这个文件是保存在tasks.json的指定的目录，在本例中是build文件夹。
#写CXX代表C++语言,写C代表C语言
project(main CXX)
#把当前目录.下所有源文件加入变量SRC_LIST，
#这里的.代表当前目录，也即当前workspace(工作区、工作空间)，本例中cc1文件夹位置。
# aux_source_directory(c_learn SRC_LIST)
#生成应用程序main，在windows下会自动生成main.exe。

add_executable(main 00_oj/t24.cpp)

#C++时下面这行要去掉
# target_compile_options(main PRIVATE "-std=c99")