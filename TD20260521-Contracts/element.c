#include <stdio.h>
#include "element.h"
 
void display_element(element e) {
    printf("  %-6s  %4s  qty=%-4d  strike=%8.2f  expiry=%-12s  premium=%6.2f\n",
           e.ticker,
           e.type==0 ? "PUT":"CALL",
           e.qty,
           e.strike,
           e.expiration,
           e.premium);
}
 
