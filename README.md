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

## SECTION-1 C++基础, CHAPTER-2 变量类型

### 一些类型

- `sizeof(int)`可以查看占用多少个byte
- byte是可以寻址的最小内存块
- 默认的整数（`int, short, long, long long`）都是signed，可以指定`unsigned int var=1;`
- `unsigned`默认指`unsigned int`

> 如何选择类型？
>
> 1. 整数：已知不可能为负数，就用unsigned
> 2. 整数：建议使用int和long long，剩下两个比较鸡肋
> 3. 浮点数：建议都用double，float有点差，long double太过分
> 4. 算数表达式不要用char和bool

类型转换：

- int 2 float 可能会有精度损失
- 赋给unsigned一个超出范围的值，得到的是mod
- 赋给signed一个超出范围的值，得到**undefined结果——这是最好避免的情况！**
- 有些时候会做隐式类型转换，比如int + unsigned，会先把int转化为uint

**尽量不要混用int和uint，因为int总是会被转化成uint，如果int是负数就会出现错误**

字面值的默认类型：

- 可以在数字前面加0表示八进制，0x表示十六进制
- 浮点数可以用e或者E
- 字符串，默认类型是char array，编译器将在末尾自动加一个` "\0" `
- 如果两个字符串之间没有字符，会被认为是同一个
- 可以用一些前缀后缀更改默认类型
- nullptr是指针字面值

### 初始化，赋值

> C++有多种赋值方式

```c++
int x = 0;
int x = {0};
int x{0};
int x(0);
```
其中带有花括号的被称为**列表初始化**，特点是不会带来精度损失（如果有损失就会报错，比如 int x=1.23;）

对于有些对象，可以不初始化，而是隐式地完成。但如果定义该对象时没有加上初始化，那么可能会引发错误。

### Declaration & Definition

- C++是静态类型，在编译期间检查类型：并确定该种类型能参与的运算。
- 如果发现对某种类型做了不该做的运算，编译就会失败；
- 很多时候，一个程序包含多个文件，并且文件之间共享变量（可以使用其他文件中定义的变量）
- C++支持分离式编译，所以将声明和定义区分开了；

- **定义, 只能一次！**:申请内存，也可能赋值；
- **声明，可以好多次！**：把一个变量加入我的作用域
- 声明并且定义：`int i;`
- 仅声明应该使用关键字：`extern int i;`
- 如果extern的同时定义，就抵消了extern的作用：`extern int x = 1;`
- 一般在某个文件中定义，在其他的很多地方声明；

### Identifier

- 只包括：字母、下划线、数字
- 开头：只能下划线和字母
- （禁止的一些是为了给标准库保留）
- 禁止！连续两个下划线开头
- 禁止！下划线开头，紧接着大写字母
- 禁止！定义在函数外的标识符不能以下划线开头

### Scope

- scope begin：声明
- scope end：声明语句所在的作用域末端为结束
- 作用域是会嵌套的；
- 如果外层（全局）和内层有同名变量x(类型也可以不一样)，在内层调用隐式地使用内层，除非用`::x`显式地访问
- `::`左侧什么都不写代表全区作用域；

```c++
#include <iostream>
int i=100, sum=0;

int main()
{
    for (int i=0; i!=10; i++)
    {
        sum += i;
    }  // for循环中定义的i在结束后就被销毁
    std::cout << i << "  " << sum << std::endl; //所以打印的全局变量i
    return 0;
}
```

### Pointer & Reference

> 使用未经初始化的指针是引发Runtime Error的一大原因。（建议全都初始化，至少要nullptr）
>
> 指针通常难以理解，即使是有经验的程序员也会因为调试指针引发的错误而备受折磨。

- **引用变量是一个别名**，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
- 指针指向一块内存

引用很容易与指针混淆，它们之间有三个主要的不同：

- 不存在空引用。引用必须连接到一块合法的内存。
- **一旦引用被初始化为一个对象，就不能被指向到另一个对象**。指针可以在任何时候指向到另一个对象。
- **引用必须在创建时被初始化**。指针可以在任何时间被初始化。

```c++
int x=12;

int *px = &x; //pointer
int &rx = x; // reference
```

- *表示取内容，`int *px` 说明`*px`是int，所以`px`是一个指向int的指针
- &表示取地址

- 空指针不指向任何对象：`int *p = nullptr; int *p = NULL; int *p = 0;`都可以; 但是`int x=0; int *px=&x;`就不是空指针
- void*指针：可以存放任意对象的地址，但是**不能操作对应的对象（因为不知道是什么类型，也就不知道能做什么）**
- 指向指针的指针：`int x=0, *p=&x, **pp=&p;`
- 指向指针的引用：可以的
- 指向引用的指针：**不存在，因为引用只是别名，不是实际的对象**
- 可以用 `if(pointer)`来判断是否为空

### const

`const int x = 42;`

- 这个关键字可以使得变量不能被修改（否则报错）——同时必须初始化
- 编译期间，会直接用字面值替换每个使用的地方
- 只能在const变量所在的文件里生效；不同文件里即使同名，也代表着不同的变量；
- 想要共享，只能在一个文件里用extern定义，其他文件里extern声明，**全都要用extern**

### reference of const

