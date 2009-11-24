#ifndef __W64CRT_H
#define __W64CRT_H

#include <w64crt_defs.h>

/* Internal crt locking.  */
typedef enum eW64CrtLocks {
  _LOCKTAB_LOCK = 0,
  _GLOBAL_LOCK,
  _SIGNAL_LOCK,
  _EXIT_LOCK,
  _TOTAL_LOCKS
} eW64CrtLocks;

extern void _w64_init_mtlocks (void);
extern void _w64_free_mtlocks (void);
extern void _w64_lock (int no);
extern void _w64_unlock (int no);

#ifdef _BUILD_MT
#define _mlock(NO) _w64_lock ((NO))
#define _munlock(NO) _w64_unlock ((NO))
#else
#define _mlock(NO) do { } while (0)
#define _munlock(NO) do { } while (0);
#endif

#endif

