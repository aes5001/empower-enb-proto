/* Copyright (c) 2017 Kewin Rausch
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <netinet/in.h>

#include <emproto.h>

int epf_hola_rep(
	char *   buf, unsigned int size,
	uint32_t id)
{
	ep_hola_rep * hr = (ep_hola_rep *)buf;

	hr->id = htonl(id);

	ep_dbg_dump("F - HOLA Rep: ", buf, sizeof(ep_hola_rep));

	return sizeof(ep_hola_rep);
}

int epp_hola_rep(
	char *     buf, unsigned int size,
	uint32_t * id)
{
	ep_hola_rep * hr = (ep_hola_rep *)buf;

	*id = ntohl(hr->id);

	ep_dbg_dump("P - HOLA Rep: ", buf, sizeof(ep_hola_rep));

	return 0;
}

int epf_hola_req(
	char * buf, unsigned int size,
	uint32_t id)
{
	ep_hola_req * hr = (ep_hola_req *)buf;

	hr->id = htonl(id);

	ep_dbg_dump("F - HOLA Req: ", buf, sizeof(ep_hola_req));

	return sizeof(ep_hola_req);
}

int epp_hola_req(
	char *     buf, unsigned int size,
	uint32_t * id)
{
	ep_hola_req * hr = (ep_hola_req *)buf;

	*id = ntohl(hr->id);

	ep_dbg_dump("P - HOLA Req: ", buf, sizeof(ep_hola_req));

	return 0;
}

/******************************************************************************
 * Public API                                                                 *
 ******************************************************************************/

/******************************************************************************
 * Operation on single-event messages                                         *
 ******************************************************************************/

int epf_single_hola_req(
	char *   buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t id)
{
	int ms = 0;

	ms += epf_head(
		buf, size,
		EP_TYPE_SINGLE_MSG,
		enb_id,
		cell_id,
		mod_id);

	ms += epf_single(
		buf + ms,
		size - ms,
		EP_ACT_HOLA,
		EP_OPERATION_UNSPECIFIED,
		EP_DIR_REQUEST);

	ms += epf_hola_req(buf + ms, size - ms, id);
	epf_msg_length(buf, size, ms);

	return ms;
}


int epp_single_hola_req(
	char *     buf, unsigned int size,
	uint32_t * id)
{
	return epp_hola_req(
		buf + sizeof(ep_hdr) + sizeof(ep_s_hdr),
		size,
		id);
}

int epf_single_hola_rep(
	char *   buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t id)
{
	int ms = 0;

	ms += epf_head(
		buf, size,
		EP_TYPE_SINGLE_MSG,
		enb_id,
		cell_id,
		mod_id);

	ms += epf_single(
		buf + ms,
		size - ms,
		EP_ACT_HOLA,
		EP_OPERATION_SUCCESS,
		EP_DIR_REPLY);

	ms += epf_hola_rep(buf + ms, size - ms, id);
	epf_msg_length(buf, size, ms);

	return ms;
}

int epp_single_hola_rep(
	char *     buf, unsigned int size,
	uint32_t * id)
{
	return epp_hola_rep(
		buf + sizeof(ep_hdr) + sizeof(ep_s_hdr),
		size,
		id);
}
/******************************************************************************
 * Operation on schedule-event messages                                       *
 ******************************************************************************/

int epf_sched_hola_req(
	char *   buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t interval,
	uint32_t id)
{
	int ms = 0;

	ms += epf_head(
		buf, size,
		EP_TYPE_SCHEDULE_MSG,
		enb_id,
		cell_id,
		mod_id);

	ms += epf_schedule(
		buf + ms,
		size - ms,
		EP_ACT_HOLA,
		EP_OPERATION_UNSPECIFIED,
		EP_DIR_REQUEST,
		interval);

	ms += epf_hola_req(buf + ms, size - ms, id);
	epf_msg_length(buf, size, ms);

	return ms;
}


int epp_sched_hola_req(
	char *     buf, unsigned int size,
	uint32_t * id)
{
	return epp_hola_req(
		buf + sizeof(ep_hdr) + sizeof(ep_c_hdr),
		size,
		id);
}


int epf_sched_hola_rep(
	char *   buf, unsigned int size,
	uint32_t enb_id,
	uint16_t cell_id,
	uint32_t mod_id,
	uint32_t interval,
	uint32_t id)
{
	int ms = 0;

	ms += epf_head(
		buf, size,
		EP_TYPE_SCHEDULE_MSG,
		enb_id,
		cell_id,
		mod_id);

	ms += epf_schedule(
		buf + ms,
		size - ms,
		EP_ACT_HOLA,
		EP_OPERATION_SUCCESS,
		EP_DIR_REPLY,
		interval);

	ms += epf_hola_rep(buf + ms, size - ms, id);
	epf_msg_length(buf, size, ms);

	return ms;
}


int epp_sched_hola_rep(
	char *     buf, unsigned int size,
	uint32_t * id)
{
	return epp_hola_rep(
		buf + sizeof(ep_hdr) + sizeof(ep_c_hdr),
		size,
		id);
}
