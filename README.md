*This project has been created as part of the 42 curriculum by msumiji.*

# get_next_line

## Description

　このプロジェクトではget_next_lineという関数を作成します。この関数はテキストファイルから1行ずつテキストを読み込んで表示するものです。
　get_next_lineの引数はファイルディスクリプタfdで、fdに0を指定したときはターミナルからの入力を受け取ります。テキストファイルの文字を読み取るには、
fd = open("output.txt", O_RDONLY);
とします。

## Instructions
　この関数をコンパイルする場合、

ライブラリを作成するには、次のコマンドを実行します。

```bash
make
```

これにより、rootディレクトリに `libftprintf.a` が作成されます。

オブジェクトファイルを削除するには、次のコマンドを実行します。

```bash
make clean
```

オブジェクトファイルと `libftprintf.a` を削除するには、次のコマンドを実行します。

```bash
make fclean
```

最初から作り直すには、次のコマンドを実行します。

```bash
make re
```

例えばmain.cというファイルをlibftprintf.aを使って実行する場合には、ターミナルで以下のコマンドで実行します。
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
ここで、-Lはライブラリを探す場所としてカレントディレクトリを指定しています。-lftprintfはlibftprintf.aをリンクするという意味になります。


## Resources

このプロジェクトでは、以下の資料を参考にしました。

- 42 ft_printf subject
- Linux man pages
- googleによる検索

## AI Usage

AIは、主に学習補助として使用しました。具体的には、エラーメッセージの意味の確認、文章の添削、Makefileの動作説明、ポインタやメモリ操作の理解、連結リスト関数の考え方の整理に使用しました。

AIが提示した内容は、そのまま提出物として用いるのではなく、自分でコンパイル、Norminette、テスターを実行して確認しました。

# ft_printf

## Description
This project aims to create a function called 'ft_printf' that replicates the 'printf' function included in the C standard library. However, it does not fully replicate all of `printf`’s features; rather, it is a function that replicates only a subset of those features.

ft_printf consists of a main function `ft_printf` and its helper functions. These are integrated into a header file named `ft_printf.h`, and using a Makefile compiled into a static library named `libftprintf.a`.

The basic usage of C's `printf` is to display a string enclosed in a couple of double quotes. If a string contains an identifier following a %, the value passed as a variable-length argument is output in that position.
For example,
printf(“I am %d years old”, 52);
In this case, everything except %d is displayed as usual, and the integer following %d—in this case, 52—is displayed. Therefore, when this program is executed, “I am 52 years old” will be displayed.
In this project, nine types of identifiers following the % character were handled: cspdiuxX%. In actual printf, there are various other format specifiers, such as %f and %5d. Additionally, the behavior is undefined if an identifier not defined in printf, such as %y, is specified. In ft_printf, if an unsupported identifier follows the %, it is output as a string as-is.

## Instructions

To build the library, run the following command:

```bash
make
```

This will create `libftprintf.a` in the root directory.

To delete the object files, run the following command:

```bash
make clean
```

To delete both the object files and `libftprintf.a`, run the following command:

```bash
make fclean
```

To rebuild from scratch, run the following command:

```bash
make re
```

For example, to compile a file named `main.c` using `libftprintf.a`, run the following command in the terminal:
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
Here, `-L` specifies the current directory as the location to search for libraries. `-lftprintf` means to link against `libftprintf.a`.

## Resources

The following materials were refered to for this project.

- 42 ft_printf subject
- Linux man pages
- Google searches
