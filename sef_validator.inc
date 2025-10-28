

#if defined _validator_inc
    #undef _validator_inc
#endif

#if defined _validator_inc_included
    #endinput
#endif
#define _validator_inc_included

#if !defined _samp_included
    #error "The `a_samp` library has not been activated. Please activate it at the beginning of your Gamemode, Ex: `#include <a_samp>`"
#endif

/*

                                                       
                   _____ _____ __    _____ ____  _____ _____ _____ _____ 
                  |  |  |  _  |  |  |     |    \|  _  |_   _|     | __  |
                  |  |  |     |  |__|-   -|  |  |     | | | |  |  |    -|
                   \___/|__|__|_____|_____|____/|__|__| |_| |_____|__|__|

                ___________________________________________________________          

            Essa é a forma mais eficaz pois leva em consideração a hora que foi criado.
        
            Ex: 
                se o cara receber um VIP de 1 dia e for 23 horas, só vai vencer nas 23 horas
                do dia seguinte.
 */

#define __days (gettime() / 86400)

#define validator_setdays(%0, %1) \
    if (!%0) %0 = (__days+%1); \
    else %0 = (%1 * 86400);

#define validator_isvalid(%0) ((%0 < __days))

#define time_to_seg(%0, %1, %2) ((%0*86400) + (%1*3600) + (%2*60))