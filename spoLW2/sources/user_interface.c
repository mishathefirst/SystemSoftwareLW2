#include "../headers/user_interface.h"
#include "../headers/operations_ext.h"
#include "limits.h"

char* execute_operation(struct commands command, struct state* fs_state){
    switch (command.type) {
        case LS:
            return execute_ext_ls(fs_state);
            break;
        case PWD:
            return execute_ext_pwd(fs_state);
            break;
        case CD:
            return execute_ext_cd(fs_state, command.first_argument);
            break;
        case CP:
            return execute_ext_cp(fs_state, command.first_argument, command.second_argument);
            break;
        default:
            return execute_help();
    }
}

char* entrance(char* path, char* command1){
    //char textForOutput[] = "Text for output";
    //textForOutput ;
    //return textForOutput;

    struct state* fs_state = setup(path);
    if (fs_state != NULL){
        //printf("Enter a command:\n");
        //char input[LINE_MAX];
        fgets_wrapper(command1, LINE_MAX, stdin);
        struct commands command = parse_command(command1);
        //while (command.type != QUIT){
            return execute_operation(command, fs_state);
            //printf("Enter a command:\n");
            fgets_wrapper(command1, LINE_MAX, stdin);
            command = parse_command(command1);
        //}
        printf("Stopping the app.\n");
        return 0;
    }
    else return "No data";
}

