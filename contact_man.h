/*******************************************************************************
 *
 * Copyright (c) 2016
 * Lumi, JSC.
 * All Rights Reserved
 *
 *
 * Description: Include file for application
 *
 * Author: TrungTQ
 *
 * Last Changed By:  $Author: trungtq $
 * Revision:         $Revision: 2.1 $
 * Last Changed:     $Date: 2016-06-21 15:25:00 (Tue, 21 Jun 2016) $
 * 
 *
 ******************************************************************************/
#ifndef _STATE_ENDPOINT_H_
#define _STATE_ENDPOINT_H_

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <ZW_typedefs.h>
#include "lumi_cmd.h"

/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
/**
 * @func   ContactGetValue
 * @brief  Set value of endpoint
 * @param  None
 * @retval None
 */
void
ContactSetValue(
    BYTE byValue,
    BYTE byEndpoint
);


void 
HandleContact(
    CMD_BUFFER* pCmd, 
    BYTE byLength
);


extern void
HandleContactLevel(
    BYTE byLevel,
    BYTE byEndpoint
);


/**
 * @func   ContactGetValue
 * @brief  Get Value of endpoint
 * @param  None
 * @retval None
 */
BYTE
ContactGetValue(
    BYTE byEndpoint
);

#endif /* _STATE_ENDPOINT_H_ */
