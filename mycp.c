#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, const char *argv[]) {
  // 按只读模式打开文件1, 只写模式打开文件2
  // 若无文件2则创建，若已有文件2则清空
  int inf = open(argv[1], O_RDONLY, 0), outf = open(argv[2],  O_WRONLY|O_CREAT|O_TRUNC, 0600);
  char buf[4096]; ssize_t i;
  do {
    i = read(inf, buf, 4096);
    write(outf, buf, i);
  } while(i);
  close(outf); close(inf);
}


