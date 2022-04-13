/*
** FreeBSD hello KLD
** github.com/g4br13I
*/

#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

// carregamento do modulo
static int func(struct module *teste, int switchh, void *blabla) {
    int retorno=0;
    switch(switchh) {
    case MOD_LOAD:
        uprintf("[+] hello kernel module loaded\n");
        break;
    case MOD_UNLOAD:
        uprintf("[-] hello kernel module unloaded\n");
        break;
    default:
        retorno = EOPNOTSUPP;
        break;
    }
    return(retorno);
}

static moduledata_t hello = {"hello", func, NULL};
DECLARE_MODULE(hello, func, SI_SUB_KLD, SI_ORDER_MIDDLE);
