
/*
** FreeBSD hello KLD
** github.com/g4br13I
*/

#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static int func(struct module_t tweste, int switchh, void *blabla) {
    int retorno=0;
    switch(switchh) {
    case MOD_LOAD:
        uprintf("hello kernel module loaded\n");
        break;
    case MOD_UNLOAD:
        uprintf("hello kernel module unloaded\n");
        break;
    default:
        retorno = EOPNOTSUPP;
        break;
    }
    return(retorno);
}

static moduledata_t hellou = {"hello", func, NULL};

MODULE_VERSION(hello, 1);
DECLARE_MODULE(hello, hellou, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
