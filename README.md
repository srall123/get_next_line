<h1 align="center">
	📚👨🏻‍💻<i>42_Cursus: </i>get_next_line
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/srall123/get_next_line?color=lightblue&style=plastic&logo=42" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/srall123/get_next_line?color=green&label=C%20language&logo=42&style=plastic" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/srall123/get_next_line?color=critical&logo=42&style=plastic" />
</p>
<p align="center">
	<a href="./README.md">English &nbsp;&nbsp;</a>
	<a href="./ForREADME/README_CN.md"> 简体中文 &nbsp;&nbsp; </a>
</p><hr>

## 💡 Project
This project aims to write a function which can return a line read from a file descriptor. You can learn static variables, Input-output system calls and deeper understanding of memory usage and free from this project.

This is an implementation of the get_next_line function in C, which is used for reading a file line by line. It uses a buffer to read data from the file and concatenates it with a temporary string (temp_string, implement in `gettempstr` & `ft_joint`) until EOF or a newline character is found. The temp_string consists of two parts: line_string and static_string.

In the `ft_line` function, it extracts the string containing the first `'\n'` in the temp_string as the line to be returned. In the `ft_staticstr`, it extracts the string after the first `'\n'` in the temp_string and returns it as the static string for the next call. If the temp_string is empty, they both returns NULL.

The function will return NULL if the following errors occurred: 

- open file failed；
- read file failed；
- Memory allocated failed；
  
For more details: [See this Subject ](./en.subject.pdf)

## 🧰 Usage
Using `cc` compiler to compile your source files with `-Werror -Wall -Wextra` flags. In addition, you have to handle the different buffer size, add the `-D BUFFER_SIZE=n` to your compiler call. 

```SHELL
git clone https://github.com/srall123/get_next_line.git
cc -Werror -Wextra -Wall -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c main.c && ./a.out
```
  
## 🔍 Note
- No Norm checking;
- Comments in the source files, ignore the chinese comments;

## 🛡️ Tester
Third party tester to fully test the project, thanks to contributor:
[Tripouille/gnlTester](https://github.com/Tripouille/gnlTester) `git clone https://github.com/Tripouille/gnlTester.git`
<b>The test result of mandatory and bonus:</b>
<img style="vertical-align: top;" decoding="async" src="./ForREADME/test_result.png" width="50%"><img style="vertical-align: top;" decoding="async" src="./ForREADME/test_result_bonus.png" width="50%">

## ✔︎Moulinette
<p align="center">
<img decoding="async" src="./ForREADME/score.png" width="40%">
</p>
