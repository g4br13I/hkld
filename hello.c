/*
** FreeBSD hello kernel module
** github.com/g4br13I
*/

#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>
#include <sys/param.h>

#define retorno 0

static int func(module_t teste __unused, int switchh, void *blabla __unused) {
    switch(switchh) {
    case MOD_LOAD:
        uprintf("\033[92m[+] hello kernel module loaded\033[0m\n");
        break;
    case MOD_UNLOAD:
        uprintf("\033[91m[-]\033[0m hello kernel module unloaded\033[0m\n");
        break;
    default:
        retorno = EOPNOTSUPP;
        break;
    }
    return(retorno);
}

static moduledata_t hello = {"hello", func, NULL};
DECLARE_MODULE(hello, func, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
