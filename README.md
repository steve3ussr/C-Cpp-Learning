# C-Cpp-Learning

> What I will do with this repo:
>
> - Learn C/C++ with "C++ Primer"
>

## Quick Start

### A Simple Function

> 1.1 编写一个简单的C++程序

下面是一个基本的函数定义：

应该注意几点：

- parameters指函数define&declare时候的参数
- arguments指函数call的时候的参数
- statements必须有分号

```c++
return_types main(parameters)
{
    statements;
}
```

编译与执行：

- 在windows上通常可以由vscode+gcc一键编译+执行
- linux上可能需要g++先编译，然后在使用`./cpp.out`执行
- 因为不加`./`·会在PATH中寻找，而我们需要在wd下寻找

```c++
// 一个使用IO，输入两个整数并且返回和的程序
#include <iostream>

int main()
{
    int x, y;
    std::cin >> x >> y;
    std::cout << "result is: " << x+y << std::endl;
    return 0;
}
```

提示：

- `std::endl`相比`\n`的好处是可以及时刷新缓冲区
- 标准库定义的所有名字都在std这个namaspace里

### Flow Control

#### while循环

```c++
while (condition)
{
    statements;
}
```

#### for循环

```c++
for (init ; condition ; expression)
{
    statements;
}
```

- 所有的语句都是，可有可无，根据情况；
- init 控制初始化的循环变量；
- condition 控制条件；
- expression 控制每次执行完 statements 的操作；

#### if

```c++
if (condition)
{
    statements;
}

if (condition)
{
    statements;
}
else
{
    statements;
}
```

### 类 (include, usage)

- `#include`导入的东西，尖括号是内置的标准库，双引号是任何库；
- 可以相对路径，比如`"../GCC_4_7_0/1/Sales_item.h"`
- 可以绝对路径，比如`/home/C-Cpp-Learning/GCC_4_7_0/1/Sales_item.h`

- 在给的例子中，重载了一些操作符，使得这个类支持更多的操作；
- 为了避免手动输入可以在bash中重定向流，比如我将`boook 4 13`写入一个文件
- `./xxx.out <infile >outfile`可以重定向文件流








### 不定长参数

通过std::cin读取参数

```c++
int main()
{
    int s=0, v;
    while (std::cin >> v)
    {
        s += v;
    }
    std::cout << s << std::endl;
    return 0;
}
```

- 输入形式应该是`1 2 54 回车`, 或者 `1 \n 2 \n 54\n`
- 当出现错误时，cin对象的状态变为无效，循环结束
- 也可以用Ctrl+D 表示输入结束

