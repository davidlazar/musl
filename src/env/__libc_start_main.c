#include "libc.h"

void __init_security(size_t *);

int __libc_start_main_0(
	int (*main)(void), int argc, char **argv,
	int (*init)(int, char **, char **), void (*fini)(void),
	void (*ldso_fini)(void))
{
	char **envp = argv+argc+1, **auxv = envp;

	__environ = envp;
//	do auxv++; while (*auxv);
//	libc.auxv = (void *)++auxv;
	libc.ldso_fini = ldso_fini;
	libc.fini = fini;

//	__init_security((void *)auxv);

	/* Execute constructors (static) linked into the application */
	if (init) init(argc, argv, envp);

	/* Pass control to to application */
	exit(main());
	return 0;
}

int __libc_start_main_2(
	int (*main)(int, char **), int argc, char **argv,
	int (*init)(int, char **, char **), void (*fini)(void),
	void (*ldso_fini)(void))
{
	char **envp = argv+argc+1, **auxv = envp;

	__environ = envp;
	do auxv++; while (*auxv);
	libc.auxv = (void *)++auxv;
	libc.ldso_fini = ldso_fini;
	libc.fini = fini;

	__init_security((void *)auxv);

	/* Execute constructors (static) linked into the application */
	if (init) init(argc, argv, envp);

	/* Pass control to to application */
	exit(main(argc, argv));
	return 0;
}

int __libc_start_main_3(
	int (*main)(int, char **, char **), int argc, char **argv,
	int (*init)(int, char **, char **), void (*fini)(void),
	void (*ldso_fini)(void))
{
	char **envp = argv+argc+1, **auxv = envp;

	__environ = envp;
	do auxv++; while (*auxv);
	libc.auxv = (void *)++auxv;
	libc.ldso_fini = ldso_fini;
	libc.fini = fini;

	__init_security((void *)auxv);

	/* Execute constructors (static) linked into the application */
	if (init) init(argc, argv, envp);

	/* Pass control to to application */
	exit(main(argc, argv, envp));
	return 0;
}
