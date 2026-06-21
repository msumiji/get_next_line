*This project has been created as part of the 42 curriculum by msumiji.*

# get_next_line

## Description

　このプロジェクトではget_next_lineという関数を作成します。この関数はテキストファイルから1行ずつテキストを読み込んで表示するものです。
　get_next_lineの引数はファイルディスクリプタfdで、fdに0を指定したときはターミナルからの入力を受け取ります。テキストファイルの文字を読み取るには、
fd = open("output.txt", O_RDONLY);
とします。
　以下にget_next_lineで使った関数の説明をします。

get_next_line このプロジェクトの主となる関数で全体的な制御をします。ファイルを読み込んだ内容はsaveというstatic char変数に保存されます。

readandsave　改行が現れるまでファイルを読み込んでその内容をsaveに保存します。

findnewline　文字列の中から最初の改行が現れる文字の位置を返します。改行がない場合、あるいは文字列のポインタがNULLの場合は-1を返します。

afternewline　文字列の中で改行より後の部分だけを抜き出して返します。文字列のポインタがNULLの場合はNULLを返します。

beforenewline　文字列の中で改行より前の部分（改行を含む）に終端文字を加えて返します。改行がない場合、あるいはヌルポインタの場合は文字列をそのまま返します。

ft_strlen　文字列の長さを測ります。libftのft_strlenと同じ。

ft_memcpy メモリを他のメモリに移します。これもlibftのft_memcpyと同じ。

ft_strjoin 文字列s1の後ろに文字列s2をつなげ、終端文字を加えます。s1がヌルポインタの場合はs2をそのまま返します。s2がヌルポインタの場合はNULLを返します。

ft_strdup　渡された文字列と同じ文字列を新しく確保された領域に入れて返します。これもlibftのft_strdupと同じ。

change_null　渡された文字列をfreeしてNULLを返します。

## Instructions

　この関数をコンパイルする場合、ターミナルで以下のコマンドを入力します。
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c

これにより、rootディレクトリに `a.out` が作成され、./a.outと入力することでプログラムが実行されます。

## Resources

このプロジェクトでは、以下の資料を参考にしました。

- 42 ft_printf subject
- Linux man pages
- googleによる検索

## AI Usage

　AIは、主に学習補助として使用しました。具体的には、エラーメッセージの意味の確認、文章の添削、テキストの作成、ポインタやメモリ操作の理解、連結リスト関数の考え方の整理に使用しました。AIが提示した内容は、そのまま提出物として用いるのではなく、自分でコンパイル、Norminette、テスターを実行して確認しました。

## Algorithm
　このプログラムでは、static char変数saveを使って文字列の制御をします。まずsaveに改行があるかを判断し、改行がある場合には、改行前の文字列をmain関数に返し、改行後の文字列を新たなsaveに残します。saveに改行がない場合にはreadで改行が現れるまで読み込みを続けます。saveは次にget_next_lineが読み込まれるまで保存されます。
