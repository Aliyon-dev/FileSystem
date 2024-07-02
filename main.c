#include <stdio.h>
#include <string.h>





// THE FILE DIRECTORY AND ITS METHODS  //
typedef struct{
    char name[100];
    struct Directory* parent;
    char subitems[100][100];
    int subitem_types[100];
    int subitem_count;
}Directory;

Directory* create_root_dir(){
    Directory* root = (Directory*)malloc(sizeof(Directory));
    strcpy(root -> name, "root");
    root->subitem_count = 0;
    return root;
}

Directory* create_dir(const char* dir_name, Directory* root){
    //check if the folder already exist
    for(int i =0; i<root->subitem_count; i++){
        if(strcmp(root->subitems[i], dir_name)==0){
            printf("directory name already exist");
            return -1;
        }
    }
    /// we check if the subitem count is full
    if(root->subitem_count>=100){
        printf("root directory is full");
        return -2;
    }
    // we now create the directory
    Directory* dir = (Directory*)malloc(sizeof(Directory));
    strcpy(dir->name, dir_name);
    dir->parent = root;
    // add it to the current directory
    strcpy(root->subitems[root->subitem_count], dir_name);
    root->subitem_types[root->subitem_count] = 1; // Directory type
    root->subitem_count++;

    return dir;
}

Directory* delete_dir(){};
Directory* change_dir(){};


//  END OF DIRECTORY AND ITS METHODS   //


int main(){
    Directory* root = create_root_dir();
    Directory* my_dir = create_dir("pics", root);

    printf(my_dir);


    return 0;
}