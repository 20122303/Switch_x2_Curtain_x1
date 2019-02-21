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
 ******************************************************************************/

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "config_app.h"
#include "macro.h"
#include "lumi_serial_api.h"
#include "setup_device.h"
#include "convert_data.h"
#include "contact_man.h"

/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
static BYTE g_pbValueEP[NUMBER_OF_SWITCH] = { 0 };

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
 * @func   ContactSetValue
 * @brief  None
 * @param  None
 * @retval None
 */
void
ContactSetValue(
    BYTE byValue,
    BYTE byEndP
) {
	if (byEndP == 0) {
		g_pbValueEP[0] = CorrectValue(byValue, DEVICE_CONTACT);		
	}
    else if ( (byEndP - INDEX_SWITCH_BASE) < NUMBER_OF_SWITCH ) {
        g_pbValueEP[byEndP - INDEX_SWITCH_BASE] = CorrectValue(byValue, DEVICE_CONTACT);
    }
}


void
HandleContact(
    CMD_BUFFER* pCmd, 
    BYTE byLength
) {
    BYTE byValue = 0;
    UNUSED(byLength);

	if ((pCmd->lumi_contact.no - INDEX_SWITCH_BASE) < NUMBER_OF_SWITCH )
		HandleContactLevel(ConvertValueMcuToZw(pCmd->lumi_contact.val, DEVICE_CONTACT), pCmd->lumi_contact.no);
}


/**
 * @func   ContactGetValue  
 * @brief  None
 * @param  None
 * @retval None
 */
BYTE
ContactGetValue(
    BYTE byEndP
) {
	if (byEndP == 0) {
		return g_pbValueEP[0];
	}
    else if ( (byEndP - INDEX_SWITCH_BASE) < NUMBER_OF_SWITCH ) {
        return g_pbValueEP[byEndP - INDEX_SWITCH_BASE];
    }
    return 0;
}
