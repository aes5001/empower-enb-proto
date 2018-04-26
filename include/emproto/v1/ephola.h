/******************************************************************************
 * MY Code - hola start                                             *
 ******************************************************************************/
#ifndef __EMAGE_PROTOCOLS_HOLA_H
#define __EMAGE_PROTOCOLS_HOLA_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */



/*
 * Hola message
 */

typedef struct __ep_hola_reply {
	uint32_t id;
}__attribute__((packed)) ep_hola_rep;

typedef struct __ep_hola_request {
	uint32_t id;
}__attribute__((packed)) ep_hola_req;

/******************************************************************************
 * Operation on single-event messages                                         *
 ******************************************************************************/

/* Format an Hola request message with the desired fields.
 * Returns the size of the message, or a negative error number.
 */
int epf_single_hola_req(
	char *   buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t id);

/* Parse an Hola request message */
int epp_single_hola_req(
	char *     buf, unsigned int size,
	uint32_t * id);

/* Format an Hola reply message with the desired fields.
 * Returns the size of the message, or a negative error number.
 */
int epf_single_hola_rep(
	char *   buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t id);

/* Parse an Hola reply message */
int epp_single_hola_rep(
	char *     buf, unsigned int size,
	uint32_t * id);

/******************************************************************************
 * Operation on schedule-event messages                                       *
 ******************************************************************************/

/* Format an Hola request message with the desired fields.
 * Returns the size of the message, or a negative error number.
 */
int epf_sched_hola_req(
	char * buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t interval,
	uint32_t id);

/* Parse an Hola request message */
int epp_sched_hola_req(
	char * buf, unsigned int size,
	uint32_t * id);

/* Format an Hola reply message with the desired fields.
 * Returns the size of the message, or a negative error number.
 */
int epf_sched_hola_rep(
	char * buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t interval,
	uint32_t id);

/* Parse an Hola reply message */
int epp_sched_hola_rep(
	char * buf, unsigned int size,
	uint32_t * id);

/******************************************************************************
 * Operation on trigger-event messages                                        *
 ******************************************************************************/
/******************************************************************************
 * MY Code - hola finish                                            *
 ******************************************************************************/



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __EMAGE_PROTOCOLS_HELLO_H */

