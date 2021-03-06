#ifndef _SPAWN_H
#define _SPAWN_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_mode_t
#define __NEED_pid_t
#define __NEED_sigset_t

#include <bits/alltypes.h>

struct sched_param;

#define POSIX_SPAWN_RESETIDS 1
#define POSIX_SPAWN_SETPGROUP 2
#define POSIX_SPAWN_SETSIGDEF 4
#define POSIX_SPAWN_SETSIGMASK 8
#define POSIX_SPAWN_SETSCHEDPARAM 16
#define POSIX_SPAWN_SETSCHEDULER 32

typedef struct {
	int __flags;
	pid_t __pgrp;
	sigset_t __def, __mask;
	int __prio, __pol, __pad[16];
} posix_spawnattr_t;

typedef struct {
	int __pad0[2];
	void *__actions;
	int __pad[16];
} posix_spawn_file_actions_t;

int posix_spawn(pid_t *, const char *, const posix_spawn_file_actions_t *,
	const posix_spawnattr_t *, char *const [], char *const []);
int posix_spawnp(pid_t *, const char *, const posix_spawn_file_actions_t *,
	const posix_spawnattr_t *, char *const [], char *const []);

int posix_spawnattr_init(posix_spawnattr_t *);
int posix_spawnattr_destroy(posix_spawnattr_t *);

int posix_spawnattr_setflags(posix_spawnattr_t *, short);
int posix_spawnattr_getflags(const posix_spawnattr_t *, short *);

int posix_spawnattr_setpgroup(posix_spawnattr_t *, pid_t);
int posix_spawnattr_getpgroup(const posix_spawnattr_t *, pid_t *);

int posix_spawnattr_setsigmask(posix_spawnattr_t *, const sigset_t *);
int posix_spawnattr_getsigmask(const posix_spawnattr_t *, sigset_t *);

int posix_spawnattr_setsigdefault(posix_spawnattr_t *, const sigset_t *);
int posix_spawnattr_getsigdefault(const posix_spawnattr_t *, sigset_t *);

int posix_spawn_file_actions_init(posix_spawn_file_actions_t *);
int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *);

int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t *, int, const char *, int, mode_t);
int posix_spawn_file_actions_addclose(posix_spawn_file_actions_t *, int);
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *, int, int);

#ifdef __cplusplus
}
#endif

#endif
