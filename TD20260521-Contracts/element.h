#pragma once
#include <stddef.h>

#define TICKER_LEN  8
#define EXPIRY_LEN  12
typedef enum {
    PUT=0,
    CALL=1,
} contract_type;

typedef struct {
    char   ticker[TICKER_LEN];   /* e.g. "AAPL"        */
    contract_type type;          /* 0 or 1 */
    int    qty;                  /* number of contracts */
    double strike;               /* strike price        */
    char   expiration[EXPIRY_LEN]; /* e.g. "2025-06-20" */
    double premium;              /* premium per share   */
} contract;

typedef contract element;

void display_element(element e);
