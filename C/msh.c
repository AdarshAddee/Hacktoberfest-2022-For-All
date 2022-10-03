// GitHub username: muditmahajan
// Aim: MSH is a simple shell implementation in C with few builtin commands.
// Date: 03 October 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//defines
#define msh_read_line_BUFFER_SIZE 1024
#define msh_token_BUFFER_SIZE 64
#define msh_token_delimeter " \t\n\r\a"

//Functions
char *msh_read_line(void);
void msh_loop(void);

void buffer_allocation_error(void);
char ** msh_parse_arguments(char *line);
int msh_launch_process(char ** argc);
int msh_execute(char ** args);

//Command Functions
int msh_cd(char ** args);
int msh_help(char ** args);
int msh_exit(char ** args);
int msh_pwd(char ** args);

int main(int argc, char **argv)
{   
    //Main loop of the shell.
    msh_loop();

    return 0;
}

//array of built-in command names
char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "pwd"
};

//function pointers
int (*builtin_func[]) (char **) = {
    &msh_cd,
    &msh_help,
    &msh_exit,
    &msh_pwd
};

//return size
int msh_num_builtins(void) {
    return sizeof(builtin_str) / sizeof(char *);
}

//Functions to change directory
int msh_cd(char ** args)
{
    if(args[1] == NULL) 
    {
        fprintf(stderr, "Error: msh: expected arguments to \"cd\".\n");
    }
    else
    {
        if(chdir(args[1]) != 0)
        {
            perror("Error: msh");
        }
    }
    return 1;
}

//Functions to print a help page.
int msh_help(char ** args)
{
    printf("Mudit's Shell\n");
    printf("Usage: Easy enough!\n");
    printf("Just type program names and arguments, then press Enter.\n");
    printf("The following commands are built in:\n");

    //List all functions.
    for(int i = 0; i < msh_num_builtins(); i++)
    {
        printf("%d %s\n", i + 1, builtin_str[i]);
    }

    printf("Tip: Use the man command for more information.\n");
    return 1;
}

//Exit the shell.
int msh_exit(char ** args)
{
    return 0;
}

//Print current directory.
int msh_pwd(char ** args)
{
    char *current_directory = (char *)malloc(msh_read_line_BUFFER_SIZE);
    if(getcwd(current_directory, msh_read_line_BUFFER_SIZE) != NULL)
    {
        printf("%s \n", current_directory);
    }
    return 1;
}

//Execute a command by comparing the arguments with the array.
int msh_execute(char ** args)
{
    if(args[0] == NULL)
    {
        return 1;
    }

    for(int i = 0; i < msh_num_builtins(); i++)
    {
        if(strcmp(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }

    return msh_launch_process(args);
}



void buffer_allocation_error(void)
{   
    fprintf(stderr, "msh: Error: Buffer memory allocation error\n");
    exit(EXIT_FAILURE);
}

char *msh_read_line(void)
{   
    //allocate buffer memory
    int buffer_size = msh_read_line_BUFFER_SIZE;
    int current_position = 0;
    char *buffer = malloc(sizeof(char) * buffer_size);
    int temp;

    if(!buffer)
    {
        buffer_allocation_error();
    }

    while(1)
    {   
        //read a character
        temp = getchar();

        //if eof or new line replace last character in buffer with '\0' and return the buffer
        if(temp == EOF || temp == '\n')
        {
            temp = '\0';
            buffer[current_position++] = temp;
            return buffer;
        }
        else
        {
            buffer[current_position++] = temp;
        }

        //if exceeded the allocated memory, reallocate double memory.
        if(current_position >= msh_read_line_BUFFER_SIZE)
        {
            buffer_size += msh_read_line_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size);

            if(!buffer)
            {
                buffer_allocation_error();
            }
        }
    }
}

//Delimeter individual arguments
char ** msh_parse_arguments(char *line)
{   
    //allocating memory for token buffer
    int buffer_size = msh_token_BUFFER_SIZE;
    int current_position = 0;

    char *token;
    char **tokens = malloc(sizeof(char*) * buffer_size);

    if(!tokens)
    {
        buffer_allocation_error();
    }

    //using strtok to separate string with delimeters.
    token = strtok(line, msh_token_delimeter);

    while(token)
    {
        tokens[current_position++] = token;

        //if buffer size exceeded, reallocate
        if(current_position >= msh_token_BUFFER_SIZE)
        {
            buffer_size += msh_token_BUFFER_SIZE;
            tokens = realloc(tokens, sizeof(char*) * buffer_size);

            if(!tokens)
            {
                buffer_allocation_error();
            }
        }

        token = strtok(NULL, msh_token_delimeter);
    }

    tokens[current_position] = NULL;
    return tokens;
}

int msh_launch_process(char **args)
{
    pid_t process_id, wait_process_id;
    int status;

    process_id = fork();

    if(process_id == 0)
    {
        // child process
        if(execvp(args[0], args) == -1)
        {
            perror("Child Process Error.\n");
        }
        exit(EXIT_FAILURE);
    }
    else if(process_id < 0)
    {
        perror("Error in forking the process.\n");
    }
    else
    {
        //Parent Process
        do 
        {
            wait_process_id = waitpid(process_id, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

void msh_loop(void)
{
    char *line;     //Input line
    char ** args;   //Individual arguments
    int status;     

    do
    {
        printf("> ");

        line = msh_read_line();
        args = msh_parse_arguments(line);
        status = msh_execute(args);

        free(line);
        free(args);
    }   while(status);
}