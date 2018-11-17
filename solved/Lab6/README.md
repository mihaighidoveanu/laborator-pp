# [Lab 6](https://github.com/Mihaaai/laborator-pp/blob/master/labs/Lab6.pdf)

## Important Observations

+ fseek with SEEK_END should always be called with a negative offset
+ SEEK_END is a position after the last file byte, and SEEK_SET is a position before the first file byte. [Read more.](https://stackoverflow.com/questions/27549718/behaviour-of-fseek-and-seek-end)
```c 
int x;
fseek(f, -sizeof(int), SEEK_END);
fread(&x,sizeof(int),1,f);	// reads the LAST INTEGER from file, NOT the SECOND LAST
```

+ If we need to open files for read/write, open them with "r+b" if we need to read before write (in this case, the file has to exist already)
+ If we need to open files for read/write, open them with "w+b" if we need to write before read (in this case, the file is newly created or overwritten)

## Binary files
**[Why binary files are needed ?]**(https://chortle.ccsu.edu/java5/Notes/chap86/ch86_6.html)

To read from a binary file, you have to use [*fread*](https://en.cppreference.com/w/c/io/fread). 
It returns an int specifying how many elements it read from the input stream.

## Valid ways to read until the end of file

[feof](https://en.cppreference.com/w/c/io/feof) - **can be used for text files and binary files**
```c
while(1){
	int x;
	fread(&x,sizeof(int),1,file);
	if(feof(file)){
	    break;
	}
	printf("%d ",x);
}
```

[fgets](https://en.cppreference.com/w/c/io/fgets)
```c
char str[31]; // to have space for 30 characters, we add an extra one for the terminating null
while(fgets(str,sizeof(str),file) != NULL){
	printf("%s\n",str);
}
```

[fscanf](https://en.cppreference.com/w/c/io/fscanf)
```c
total = 0; 
while (fscanf(file, "%d", &num) == 1){
  total += num;
}
```

[fread](https://en.cppreference.com/w/c/io/fread)	- **returns the number of elements read from file**
```c
int v[10];
while (fread(v, sizeof(int), 10, file) == 10){	//reads pairs of 10 integers multiple times
  printf("%s\n", x.nume);
}
```

[fgetc](https://en.cppreference.com/w/c/io/fgetc)
```c
char c;
while ((c = fgetc(file)) != EOF){
  putchar(c);
}
```





