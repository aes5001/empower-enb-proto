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

#ifndef __EMAGE_PROTOCOLS_DIRECTION_H
#define __EMAGE_PROTOCOLS_DIRECTION_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef enum __ep_direction_type {
	EP_DIR_REQUEST = 0,     /* Request issued */
	EP_DIR_REPLY   = 1,     /* Reply issued */
} ep_dir_type;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __EMAGE_PROTOCOLS_DIRECTION_H */
