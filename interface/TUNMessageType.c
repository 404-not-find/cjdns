/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "interface/TUNMessageType.h"
#include "wire/Message.h"

#include <stdint.h>

void TUNMessageType_push(struct Message* message, uint16_t ethertype)
{
    Message_shift(message, 4);
    ((uint16_t*) message->bytes)[0] = 0;
    ((uint16_t*) message->bytes)[1] = ethertype;
}

uint16_t TUNMessageType_pop(struct Message* message)
{
    Message_shift(message, -4);
    return ((uint16_t*) message->bytes)[-1];
}
