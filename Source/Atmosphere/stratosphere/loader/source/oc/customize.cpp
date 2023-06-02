/*
 * Copyright (C) Switch-OC-Suite
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "customize.hpp"

namespace ams::ldr::oc {

//volatile EristaMtcTable EristaMtcTablePlaceholder = { .rev = ERISTA_MTC_MAGIC, };
//volatile MarikoMtcTable MarikoMtcTablePlaceholder = { .rev = MARIKO_MTC_MAGIC, };

volatile CustomizeTable C = {
/* DRAM Timing:
 * AUTO_ADJ_SAFE_MARIKO_ONLY: Auto adjust timings for Mariko LPDDR4X ≤3733 Mbps specs, 8Gb density. (Default)
 * AUTO_ADJ_4266_MARIKO_ONLY: Auto adjust timings for Mariko LPDDR4X 4266 Mbps specs, 8Gb density.
 * NO_ADJ_ALL: No timing adjustment for both Erista and Mariko.
 * CUSTOMIZED_ALL: Replace with values in customized table for both Erista and Mariko.
 */
.mtcConf = AUTO_ADJ_SAFE_MARIKO,

/* Common:
 * - Boost Clock in kHz:
 *   Default: 1785000
 *   Boost clock will be applied when applications request higher CPU frequency for quicker loading.
 *   This will be set regardless of whether sys-clk is enabled.
 */
.commonCpuBoostClock = 1785000,
/* - EMC Vddq (Erista Only) and RAM Vdd2 Voltage in uV
 *   Range: 1100'000 to 1250'000 uV
 *   Erista Default(HOS): 1125'000 (bootloader: 1100'000)
 *   Mariko Default: 1100'000 (It will not work without sys-clk-OC.)
 *   Value should be divided evenly by 12'500.
 *   Not enabled by default.
 */
.commonEmcMemVolt  = 0,

/* Erista CPU:
 * - Max Voltage in mV
 * - CpuVoltL4T: 1235
 */
.eristaCpuMaxVolt  = 1235,

/* Erista EMC(RAM):
 * - RAM Clock in kHz
 *   [WARNING]
 *   RAM overclock could be UNSTABLE if timing parameters are not suitable for your DRAM:
 *   - Graphical glitches
 *   - System instabilities
 *   - NAND corruption
 */
.eristaEmcMaxClock = 1862400,

/* Mariko CPU:
 * - Max Voltage in mV:
 *   Default voltage: 1120
 */
.marikoCpuMaxVolt    = 1235,

/* Mariko EMC(RAM):
 * - RAM Clock in kHz:
 *   Values should be ≥ 1600000, and divided evenly by 9600.
 *   [WARNING]
 *   RAM overclock could be UNSTABLE if timing parameters are not suitable for your DRAM:
 *   - Graphical glitches
 *   - System instabilities
 *   - NAND corruption
 */
.marikoEmcMaxClock = 1996800,
/* - EMC Vddq (Mariko Only) Voltage in uV
 *   Range: 550'000 to 650'000 uV
 *   Value should be divided evenly by 5'000
 *   Default: 600'000
 *   Not enabled by default.
 *   This will not work without sys-clk-OC.
 */
.marikoEmcVddqVolt = 0,

.marikoGpuUV = 0,

.ramTimingPresetOne = 0,

.ramTimingPresetTwo = 0,

.ramTimingPresetThree = 0,

.ramTimingPresetFour = 0,

.ramTimingPresetFive = 0,

.ramTimingPresetSix = 0,

.ramTimingPresetSeven = 0,

/* Advanced Settings:
 * - Erista CPU DVFS Table:
 */
.eristaCpuDvfsTable = {
    {  204000, {  721094 }, {} },
    {  306000, {  754040 }, {} },
    {  408000, {  786986 }, {} },
    {  510000, {  819932 }, {} },
    {  612000, {  852878 }, {} },
    {  714000, {  885824 }, {} },
    {  816000, {  918770 }, {} },
    {  918000, {  951716 }, {} },
    { 1020000, {  984662 }, { -2875621,  358099, -8585 } },
    { 1122000, { 1017608 }, {   -52225,  104159, -2816 } },
    { 1224000, { 1050554 }, {  1076868,    8356,  -727 } },
    { 1326000, { 1083500 }, {  2208191,  -84659,  1240 } },
    { 1428000, { 1116446 }, {  2519460, -105063,  1611 } },
    { 1581000, { 1130000 }, {  2889664, -122173,  1834 } },
    { 1683000, { 1168000 }, {  5100873, -279186,  4747 } },
    { 1785000, { 1227500 }, {  5100873, -279186,  4747 } },
    // Appending table
    { 1887000, { 1235000 }, {  5100873, -279186,  4747 } },
    { 1963500, { 1235000 }, {  5100873, -279186,  4747 } },
    { 2091000, { 1235000 }, {  5100873, -279186,  4747 } },
},

/* - Mariko CPU DVFS Table:
 * 2397000 might not work for some SoCs.
 */
.marikoCpuDvfsTable = {
    {  204000, {  721589, -12695, 27 }, {} },
    {  306000, {  747134, -14195, 27 }, {} },
    {  408000, {  776324, -15705, 27 }, {} },
    {  510000, {  809160, -17205, 27 }, {} },
    {  612000, {  845641, -18715, 27 }, {} },
    {  714000, {  885768, -20215, 27 }, {} },
    {  816000, {  929540, -21725, 27 }, {} },
    {  918000, {  976958, -23225, 27 }, {} },
    { 1020000, { 1028021, -24725, 27 }, { 1120000 } },
    { 1122000, { 1082730, -26235, 27 }, { 1120000 } },
    { 1224000, { 1141084, -27735, 27 }, { 1120000 } },
    { 1326000, { 1203084, -29245, 27 }, { 1120000 } },
    { 1428000, { 1268729, -30745, 27 }, { 1120000 } },
    { 1581000, { 1374032, -33005, 27 }, { 1120000 } },
    { 1683000, { 1448791, -34505, 27 }, { 1120000 } },
    { 1785000, { 1527196, -36015, 27 }, { 1120000 } },
    { 1887000, { 1609246, -37515, 27 }, { 1120000 } },
    { 1963500, { 1675751, -38635, 27 }, { 1120000 } },
    // Appending table
    { 2091000, { 1716501, -39395, 27 }, { 1120000 } },
    { 2193000, { 1775132, -40505, 27 }, { 1120000 } },
    { 2295000, { 1866287, -42005, 27 }, { 1120000 } },
    //{ 2397000, { 1961107, -43506, 27 }, { 1120000 } },
},

/* - Erista GPU DVFS Table:
 */
.eristaGpuDvfsTable = {
    {   76800, { }, {  814294, 8144, -940, 808, -21583, 226 } },
    {  153600, { }, {  856185, 8144, -940, 808, -21583, 226 } },
    {  230400, { }, {  898077, 8144, -940, 808, -21583, 226 } },
    {  307200, { }, {  939968, 8144, -940, 808, -21583, 226 } },
    {  384000, { }, {  981860, 8144, -940, 808, -21583, 226 } },
    {  460800, { }, { 1023751, 8144, -940, 808, -21583, 226 } },
    {  537600, { }, { 1065642, 8144, -940, 808, -21583, 226 } },
    {  614400, { }, { 1107534, 8144, -940, 808, -21583, 226 } },
    {  691200, { }, { 1149425, 8144, -940, 808, -21583, 226 } },
    {  768000, { }, { 1191317, 8144, -940, 808, -21583, 226 } },
    {  844800, { }, { 1233208, 8144, -940, 808, -21583, 226 } },
    {  921600, { }, { 1275100, 8144, -940, 808, -21583, 226 } },
 // {  998400, { }, { 1316991, 8144, -940, 808, -21583, 226 } },
},

/* - Mariko GPU DVFS Table:
 * 1305600 might not work for some SoCs.
 */
.marikoGpuDvfsTable = {
    {   76800, {}, {  610000,                                 } },
    {  153600, {}, {  610000,                                 } },
    {  230400, {}, {  610000,                                 } },
    {  307200, {}, {  610000,                                 } },
    {  384000, {}, {  610000,                                 } },
    {  460800, {}, {  610000,                                 } },
    {  537600, {}, {  801688, -10900, -163,  298, -10599, 162 } },
    {  614400, {}, {  824214,  -5743, -452,  238,  -6325,  81 } },
    {  691200, {}, {  848830,  -3903, -552,  119,  -4030,  -2 } },
    {  768000, {}, {  891575,  -4409, -584,    0,  -2849,  39 } },
    {  844800, {}, {  940071,  -5367, -602,  -60,    -63, -93 } },
    {  921600, {}, {  986765,  -6637, -614, -179,   1905, -13 } },
    {  998400, {}, { 1098475, -13529, -497, -179,   3626,   9 } },
    { 1075200, {}, { 1163644, -12688, -648,    0,   1077,  40 } },
    { 1152000, {}, { 1204812,  -9908, -830,    0,   1469, 110 } },
    { 1228800, {}, { 1277303, -11675, -859,    0,   3722, 313 } },
    { 1267200, {}, { 1335531, -12567, -867,    0,   3681, 559 } },
    // Appending table
    //{ 1305600, {}, { 1374130, -13725, -859,    0,   4442, 576 } },
},

.marikoGpuDvfsTableSLT = {
    {   76800, {}, {  590000,                                         } }, 
	{  153600, {}, {  590000,                                         } },
	{  230400, {}, {  590000,                                         } },
	{  307200, {}, {  590000,                                         } },
	{  384000, {}, {  590000,                                         } },
	{  460800, {}, {  795089, -11096,   -163,    298,  -10421,    162 } },
	{  537600, {}, {  795089, -11096,   -163,    298,  -10421,    162 } },
	{  614400, {}, {  820606,  -6285,   -452,    238,   -6182,     81 } },
	{  691200, {}, {  846289,  -4565,   -552,    119,   -3958,     -2 } },
	{  768000, {}, {  888720,  -5110,   -584,      0,   -2849,     39 } },
	{  844800, {}, {  936634,  -6089,   -602,    -60,     -99,    -93 } },
	{  921600, {}, {  982562,  -7373,   -614,   -179,    1797,    -13 } },
	{  998400, {}, { 1090179, -14125,   -497,   -179,    3518,      9 } },
	{ 1075200, {}, { 1155798, -13465,   -648,      0,    1077,     40 } },
	{ 1152000, {}, { 1198568, -10904,   -830,      0,    1469,    110 } },
	{ 1228800, {}, { 1269988, -12707,   -859,      0,    3722,    313 } },
	{ 1267200, {}, { 1308155, -13694,   -867,      0,    3681,    559 } },
},
.marikoGpuDvfsTableHiOPT = {
    {   76800, {}, {  590000,                                     } }, 
	{  153600, {}, {  590000,                                     } }, 
	{  230400, {}, {  590000,                                     } }, 
	{  307200, {}, {  590000,                                     } }, 
	{  384000, {}, {  590000,                                     } }, 
	{  460800, {}, {  590000,                                     } }, 
	{  537600, {}, {  590000,                                     } }, 
	{  614400, {}, {  590000,                                     } }, 
	{  691200, {}, {  838712, -7304,  -552,  1785, -56250,   -450 } }, 
	{  768000, {}, {  880210, -7955,  -584,     0, -42735,   8775 } }, 
	{  844800, {}, {  926398, -8892,  -602,  -900,  -5760, -20925 } }, 
	{  921600, {}, {  970060, -10108, -614, -2685,  22620,  -2925 } }, 
	{  998400, {}, { 1065665, -16075, -497, -2685,  48195,   2025 } }, 
	{ 1075200, {}, { 1132576, -16093, -648,     0,  16155,   9000 } }, 
	{ 1152000, {}, { 1180029, -14534, -830,     0,  22035,  24750 } }, 
	{ 1228800, {}, { 1248293, -16383, -859,     0,  55830,  70425 } },
},

//.eristaMtcTable = const_cast<EristaMtcTable *>(&EristaMtcTablePlaceholder),
//.marikoMtcTable = const_cast<MarikoMtcTable *>(&MarikoMtcTablePlaceholder),

};

}