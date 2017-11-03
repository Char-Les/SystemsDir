#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>

/*
  Joshua Turcotti and Charles Weng
  Systems - 4
  HW 9 - Please follow the DIRections
*/

// helper to get the size of the specified file path
long getSize(char * path){
  // pointer is used in main -> use malloc
  struct stat * stats = (struct stat *)malloc(sizeof(struct stat));
  stat(path, stats);
  return stats->st_size;
}

int main(){
  // desired path
  char * path = "./";
  printf("------------%s------------\n", path);
  // variable initializations
  DIR * directory = opendir(path);
  // keeps track of total file size, current file entry and path to file entry
  long size = 0;
  struct dirent * x;
  char temp[500];
  // loop through each entry by setting and returning x
  while ((x = readdir(directory))){
    // check if normal file elif directory
    if (x->d_type == DT_REG){
      printf("file: %s\n", x->d_name);
      // reset temp to current directory and then do the thing
      strcpy(temp, path);
      size += getSize(strcat(temp, x->d_name));

    }else if(x->d_type == DT_DIR){
      printf("directory: %s\n", x->d_name);
    }
  }
  printf("size: %lu\n", size);
}
