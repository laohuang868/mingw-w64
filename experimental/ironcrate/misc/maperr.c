#include <icrt.h>
#include <windows.h>
#include <errno.h>

static int __iCrt_mapsys2errno (unsigned long);

static int
__iCrt_mapsys2errno (unsigned long serr)
{
  switch (serr)
    {
    case ERROR_BAD_ENVIRONMENT:
      return E2BIG;
    case ERROR_ACCESS_DENIED:	case ERROR_CURRENT_DIRECTORY:
    case ERROR_LOCK_VIOLATION:	case ERROR_NETWORK_ACCESS_DENIED:
    case ERROR_CANNOT_MAKE:	case ERROR_FAIL_I24:
    case ERROR_DRIVE_LOCKED:	case ERROR_SEEK_ON_DEVICE:
    case ERROR_NOT_LOCKED:	case ERROR_LOCK_FAILED:
      return EACCES;
    case ERROR_NO_PROC_SLOTS:	case ERROR_MAX_THRDS_REACHED:
    case ERROR_NESTING_NOT_ALLOWED:
      return EAGAIN;
    case ERROR_INVALID_HANDLE:	case ERROR_INVALID_TARGET_HANDLE:
    case ERROR_DIRECT_ACCESS_HANDLE:
      return EBADF;
    case ERROR_WAIT_NO_CHILDREN:
    case ERROR_CHILD_NOT_COMPLETE:
      return ECHILD;
    case ERROR_FILE_EXISTS:
    case ERROR_ALREADY_EXISTS:
      return EEXIST;
    case ERROR_INVALID_ACCESS:	case ERROR_INVALID_FUNCTION:
    case ERROR_INVALID_DATA:	case ERROR_INVALID_PARAMETER:
    case ERROR_NEGATIVE_SEEK:
      return EINVAL;
    case ERROR_TOO_MANY_OPEN_FILES:
      return EMFILE;
    case ERROR_FILE_NOT_FOUND:	case ERROR_PATH_NOT_FOUND:
    case ERROR_INVALID_DRIVE:	case ERROR_NO_MORE_FILES:
    case ERROR_BAD_NETPATH:	case ERROR_BAD_NET_NAME:
    case ERROR_BAD_PATHNAME:	case ERROR_FILENAME_EXCED_RANGE:
      return ENOENT;
    case ERROR_BAD_FORMAT:
      return ENOEXEC;
    case ERROR_ARENA_TRASHED:	case ERROR_NOT_ENOUGH_MEMORY:
    case ERROR_INVALID_BLOCK:	case ERROR_NOT_ENOUGH_QUOTA:
      return ENOMEM;
    case ERROR_DISK_FULL:
      return ENOSPC;
    case ERROR_DIR_NOT_EMPTY:
      return ENOTEMPTY;
    case ERROR_BROKEN_PIPE:
      return EPIPE;
    case ERROR_NOT_SAME_DEVICE:
      return EXDEV;
    default:
      if (serr >= ERROR_INVALID_STARTING_CODESEG && serr <= ERROR_INFLOOP_IN_RELOC_CHAIN)
	return ENOEXEC;
      else if (serr >= ERROR_WRITE_PROTECT && serr <= ERROR_SHARING_BUFFER_EXCEEDED)
	return EACCES;
    }
  return EINVAL;
}

int
__iCrt_get_errno_from_oserr (unsigned long serr)
{
  return __iCrt_mapsys2errno (serr);
}
