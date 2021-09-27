/* WARNING: file generated by tis-mkfs tool: do not modify. */
#include "__tis_mkfs.h"
#include "mkfs_filesystem.h"

/* Contents for '.' and '..' */
struct dirent fc_dir_dot = {0, 0, 0, 0, {46, 0}};
struct dirent fc_dir_dot_dot = {0, 0, 0, 0, {46, 46, 0}};

/* inode of '/dev/stdin' */
static struct stat fc_inode_1 = {
  0,  /* ID of device containing file */
  1,  /* inode number */
  S_IFCHR | S_IRUSR | S_IRGRP | S_IROTH,  /* t_mode = kind + protection */
  1,  /* number of hard links */
  TIS_FILE_UID,  /* user ID of owner */
  TIS_FILE_GID,  /* group ID of owner */
  0,  /* TODO: device ID (if special file) */
  0,  /* total size, in bytes */
  0,  /* time of last access */
  {0,0},  /* timespec of last access */
  0,  /* time of last modification */
  {0,0},  /* timespec of last modification */
  0,  /* time of last status change */
  {0,0},  /* timespec of last status change */
  1,  /* st_blksize field */
  1  /* st_blocks field */
};
/* Contents of file '/dev/stdin' */
static unsigned char * fc_file_contents_1 (void) { return NULL; }
/* inode of '/dev/stdout' */
static struct stat fc_inode_4 = {
  0,  /* ID of device containing file */
  4,  /* inode number */
  S_IFCHR | S_IWUSR | S_IWGRP | S_IWOTH,  /* t_mode = kind + protection */
  1,  /* number of hard links */
  TIS_FILE_UID,  /* user ID of owner */
  TIS_FILE_GID,  /* group ID of owner */
  0,  /* TODO: device ID (if special file) */
  TIS_FILE_SIZE,  /* total size, in bytes */
  0,  /* time of last access */
  {0,0},  /* timespec of last access */
  0,  /* time of last modification */
  {0,0},  /* timespec of last modification */
  0,  /* time of last status change */
  {0,0},  /* timespec of last status change */
  1,  /* st_blksize field */
  1  /* st_blocks field */
};
/* Contents of file '/dev/stdout' */
static unsigned char * fc_file_contents_4 (void) { return NULL; }
/* inode of '/dev/stderr' */
static struct stat fc_inode_5 = {
  0,  /* ID of device containing file */
  5,  /* inode number */
  S_IFCHR | S_IWUSR | S_IWGRP | S_IWOTH,  /* t_mode = kind + protection */
  1,  /* number of hard links */
  TIS_FILE_UID,  /* user ID of owner */
  TIS_FILE_GID,  /* group ID of owner */
  0,  /* TODO: device ID (if special file) */
  TIS_FILE_SIZE,  /* total size, in bytes */
  0,  /* time of last access */
  {0,0},  /* timespec of last access */
  0,  /* time of last modification */
  {0,0},  /* timespec of last modification */
  0,  /* time of last status change */
  {0,0},  /* timespec of last status change */
  1,  /* st_blksize field */
  1  /* st_blocks field */
};
/* Contents of file '/dev/stderr' */
static unsigned char * fc_file_contents_5 (void) { return NULL; }
/* inode of '/dev' */
static struct stat fc_inode_2 = {
  0,  /* ID of device containing file */
  2,  /* inode number */
  S_IFDIR | TIS_FILE_MODE,  /* t_mode = kind + protection */
  1,  /* number of hard links */
  TIS_FILE_UID,  /* user ID of owner */
  TIS_FILE_GID,  /* group ID of owner */
  0,  /* TODO: device ID (if special file) */
  0,  /* total size, in bytes */
  0,  /* time of last access */
  {0,0},  /* timespec of last access */
  0,  /* time of last modification */
  {0,0},  /* timespec of last modification */
  0,  /* time of last status change */
  {0,0},  /* timespec of last status change */
  1,  /* st_blksize field */
  1  /* st_blocks field */
};
/* Entry 0 for 'stdin' in directory '/dev' */
static struct dirent fc_dir_2_0 = {
  1, /* inode number */
  0, /* offset to the next dirent */
  0, /* length of this record */
  DT_DIR, /* type of file */
  {115, 116, 100, 105, 110, 0} /* name = stdin */
};
/* Entry 1 for 'stdout' in directory '/dev' */
static struct dirent fc_dir_2_1 = {
  4, /* inode number */
  0, /* offset to the next dirent */
  0, /* length of this record */
  DT_DIR, /* type of file */
  {115, 116, 100, 111, 117, 116, 0} /* name = stdout */
};
/* Entry 2 for 'stderr' in directory '/dev' */
static struct dirent fc_dir_2_2 = {
  5, /* inode number */
  0, /* offset to the next dirent */
  0, /* length of this record */
  DT_DIR, /* type of file */
  {115, 116, 100, 101, 114, 114, 0} /* name = stderr */
};
/* Contents of directory '/dev' */
static struct dirent *fc_dir_contents_2[] = {
  &fc_dir_dot,
  &fc_dir_dot_dot,
  &fc_dir_2_0, /* stdin */
  &fc_dir_2_1, /* stdout */
  &fc_dir_2_2, /* stderr */
  0
};
/* inode of '/' */
static struct stat fc_inode_3 = {
  0,  /* ID of device containing file */
  3,  /* inode number */
  S_IFDIR | TIS_FILE_MODE,  /* t_mode = kind + protection */
  1,  /* number of hard links */
  TIS_FILE_UID,  /* user ID of owner */
  TIS_FILE_GID,  /* group ID of owner */
  0,  /* TODO: device ID (if special file) */
  0,  /* total size, in bytes */
  0,  /* time of last access */
  {0,0},  /* timespec of last access */
  0,  /* time of last modification */
  {0,0},  /* timespec of last modification */
  0,  /* time of last status change */
  {0,0},  /* timespec of last status change */
  1,  /* st_blksize field */
  1  /* st_blocks field */
};
/* Entry 0 for 'dev' in directory '/' */
static struct dirent fc_dir_3_0 = {
  2, /* inode number */
  0, /* offset to the next dirent */
  0, /* length of this record */
  DT_DIR, /* type of file */
  {100, 101, 118, 0} /* name = dev */
};
/* Contents of directory '/' */
static struct dirent *fc_dir_contents_3[] = {
  &fc_dir_dot,
  &fc_dir_dot_dot,
  &fc_dir_3_0, /* dev */
  0
};
/* inode of 'my_file' */
static struct stat fc_inode_6 = {
  0,  /* ID of device containing file */
  6,  /* inode number */
  S_IFREG | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH,  /* t_mode = kind + protection */
  1,  /* number of hard links */
  TIS_FILE_UID,  /* user ID of owner */
  TIS_FILE_GID,  /* group ID of owner */
  0,  /* TODO: device ID (if special file) */
  5,  /* total size, in bytes */
  0,  /* time of last access */
  {0,0},  /* timespec of last access */
  0,  /* time of last modification */
  {0,0},  /* timespec of last modification */
  0,  /* time of last status change */
  {0,0},  /* timespec of last status change */
  1,  /* st_blksize field */
  1  /* st_blocks field */
};
/* Contents of file 'my_file' */
static unsigned char * fc_file_contents_6_array;
static unsigned char * fc_file_contents_6 (void) {
  unsigned long sz;
  fc_file_contents_6_array = tis_inject_file ("my_file", &sz);
  return fc_file_contents_6_array;
}
/* List of files */
struct __mkfs_fs_file __mkfs_fs_files[104] = {
  {"/dev/stdin", &fc_inode_1, &fc_file_contents_1},
  {"/dev/stdout", &fc_inode_4, &fc_file_contents_4},
  {"/dev/stderr", &fc_inode_5, &fc_file_contents_5},
  {"my_file", &fc_inode_6, &fc_file_contents_6},
};
int __mkfs_fs_files_nb = 4;
int __mkfs_fs_files_nb_max = 104;
/* List of directories */
struct __mkfs_fs_dir __mkfs_fs_dirs[12] = {
  {"/", &fc_inode_3, fc_dir_contents_3},
  {"/dev", &fc_inode_2, fc_dir_contents_2},
};
int __mkfs_fs_dirs_nb = 2;
int __mkfs_fs_dirs_nb_max = 12;
struct __mkfs_fs_file * __mkfs_get_file (const char *path) {
  struct __mkfs_fs_file * r = NULL;
  //@ slevel 104;
  for (int i = 0; i < __mkfs_fs_files_nb; i++)
    if (__mkfs_fs_files[i].__mkfs_fullpath
        && strcmp(__mkfs_fs_files[i].__mkfs_fullpath, path) == 0) {
      r = &__mkfs_fs_files[i];
      break;
    }
  //@ slevel default;
  return r;
}
struct __mkfs_fs_dir * __mkfs_get_dir (const char *path) {
  struct __mkfs_fs_dir * r = NULL;
  //@ slevel 12;
  for (int i = 0; i < __mkfs_fs_dirs_nb; i++)
    if (__mkfs_fs_dirs[i].__mkfs_fullpath
        && strcmp(__mkfs_fs_dirs[i].__mkfs_fullpath, path) == 0) {
      r = &__mkfs_fs_dirs[i];
      break;
    }
  //@ slevel default;
  return r;
}
uid_t __mkfs_uid = TIS_uid;
gid_t __mkfs_gid = TIS_gid;
uid_t __mkfs_euid = TIS_euid;
gid_t __mkfs_egid = TIS_egid;


int __mkfs_next_inode = 6;
