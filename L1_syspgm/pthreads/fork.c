#include<stdio.h>
#include<unistd.h>

int main(){

for(int i = 0;i<50;i++){
for(int k=0;k<10;k++){

fork();
}

}

return 0;
}
