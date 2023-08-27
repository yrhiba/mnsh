# Minishell

Minishell is a command-line shell program, inspired by Bash, built using the C language and libc functions. It follows a similar algorithm and steps as tokenization, parsing using a tree data structure, expanding, and execution of commands. This project aims to provide a basic understanding of how shells work and offers a simplified implementation of a command-line interpreter.

## Features

- **Command Execution**: Minishell allows the execution of various commands, including built-in commands and external programs.
- **Bash-like Syntax**: The shell supports a subset of the syntax used in popular shells like Bash, making it familiar and easy to use.
- **Tokenization and Parsing**: Minishell employs a tokenizer and parser to break down user input into meaningful tokens and parse them into a command structure.
- **Variable Expansion**: The shell supports variable expansion, allowing users to utilize and manipulate environment variables.
- **Redirection and Pipes**: Minishell provides the functionality to redirect input/output and pipe output between commands.
- **Signal Handling**: The shell incorporates signal handling, allowing for graceful termination and handling of signals such as Ctrl+C.

## Getting Started

To get started with Minishell, follow these steps:

1. Clone the repository: `git clone https://github.com/yrhiba/mnsh/`
2. Navigate to the project directory: `cd minishell`
3. Compile the code using a C compiler: `make all`
4. Run the shell: `./minishell`

## Usage

Once Minishell is running, you can start entering commands. Here are a few examples to get you started:

- Execute an external program: `ls -l`
- Use built-in commands: `cd <directory>` or `echo <message>`
- Redirect input/output: `cat file.txt > output.txt` or `grep "pattern" < input.txt`
- Pipe output between commands: `ls -l | grep ".txt"`

For more information on available commands and features, refer to the documentation within Bash.
