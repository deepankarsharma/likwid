/*
 * =======================================================================================
 *
 *      Filename:  perfmon_sandybridge_counters.h
 *
 *      Description: Counter header file of perfmon module for Sandy Bridge.
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2013 Jan Treibig 
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_SANDYBRIDGE 93
#define NUM_COUNTERS_UNCORE_SANDYBRIDGE 50
#define NUM_COUNTERS_CORE_SANDYBRIDGE 8

#define OFFSET_PMC 3


#define SNB_VALID_OPTIONS_CBOX EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_EDGE_MASK|EVENT_OPTION_TID_MASK
#define SNB_VALID_OPTIONS_WBOX  EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK| \
                            EVENT_OPTION_OCCUPANCY_MASK|EVENT_OPTION_OCCUPANCY_EDGE_MASK| \
                            EVENT_OPTION_OCCUPANCY_INVERT_MASK


static RegisterMap sandybridge_counter_map[NUM_COUNTERS_SANDYBRIDGE] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, EVENT_OPTION_COUNT_KERNEL_MASK},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, EVENT_OPTION_COUNT_KERNEL_MASK},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, EVENT_OPTION_COUNT_KERNEL_MASK},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK},
    /* Temperature Sensor*/
    {"TMP0", PMC7, THERMAL, 0, 0, 0, 0, EVENT_OPTION_NONE_MASK},
    /* RAPL counters */
    {"PWR0", PMC8, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR1", PMC9, POWER, 0, MSR_PP0_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR2", PMC10, POWER, 0, MSR_PP1_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR3", PMC11, POWER, 0, MSR_DRAM_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* CBOX counters */
    {"CBOX0C0", PMC12, CBOX0, MSR_UNC_C0_PMON_CTL0, MSR_UNC_C0_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX0C1", PMC13, CBOX0, MSR_UNC_C0_PMON_CTL1, MSR_UNC_C0_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX0C2", PMC14, CBOX0, MSR_UNC_C0_PMON_CTL2, MSR_UNC_C0_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX0C3", PMC15, CBOX0, MSR_UNC_C0_PMON_CTL3, MSR_UNC_C0_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX1C0", PMC16, CBOX1, MSR_UNC_C1_PMON_CTL0, MSR_UNC_C1_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX1C1", PMC17, CBOX1, MSR_UNC_C1_PMON_CTL1, MSR_UNC_C1_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX1C2", PMC18, CBOX1, MSR_UNC_C1_PMON_CTL2, MSR_UNC_C1_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX1C3", PMC19, CBOX1, MSR_UNC_C1_PMON_CTL3, MSR_UNC_C1_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX2C0", PMC20, CBOX2, MSR_UNC_C2_PMON_CTL0, MSR_UNC_C2_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX2C1", PMC21, CBOX2, MSR_UNC_C2_PMON_CTL1, MSR_UNC_C2_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX2C2", PMC22, CBOX2, MSR_UNC_C2_PMON_CTL2, MSR_UNC_C2_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX2C3", PMC23, CBOX2, MSR_UNC_C2_PMON_CTL3, MSR_UNC_C2_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX3C0", PMC24, CBOX3, MSR_UNC_C3_PMON_CTL0, MSR_UNC_C3_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX3C1", PMC25, CBOX3, MSR_UNC_C3_PMON_CTL1, MSR_UNC_C3_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX3C2", PMC26, CBOX3, MSR_UNC_C3_PMON_CTL2, MSR_UNC_C3_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX3C3", PMC27, CBOX3, MSR_UNC_C3_PMON_CTL3, MSR_UNC_C3_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX4C0", PMC28, CBOX4, MSR_UNC_C4_PMON_CTL0, MSR_UNC_C4_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX4C1", PMC29, CBOX4, MSR_UNC_C4_PMON_CTL1, MSR_UNC_C4_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX4C2", PMC30, CBOX4, MSR_UNC_C4_PMON_CTL2, MSR_UNC_C4_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX4C3", PMC31, CBOX4, MSR_UNC_C4_PMON_CTL3, MSR_UNC_C4_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX5C0", PMC32, CBOX5, MSR_UNC_C5_PMON_CTL0, MSR_UNC_C5_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX5C1", PMC33, CBOX5, MSR_UNC_C5_PMON_CTL1, MSR_UNC_C5_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX5C2", PMC34, CBOX5, MSR_UNC_C5_PMON_CTL2, MSR_UNC_C5_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX5C3", PMC35, CBOX5, MSR_UNC_C5_PMON_CTL3, MSR_UNC_C5_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX6C0", PMC36, CBOX6, MSR_UNC_C6_PMON_CTL0, MSR_UNC_C6_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX6C1", PMC37, CBOX6, MSR_UNC_C6_PMON_CTL1, MSR_UNC_C6_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX6C2", PMC38, CBOX6, MSR_UNC_C6_PMON_CTL2, MSR_UNC_C6_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX6C3", PMC39, CBOX6, MSR_UNC_C6_PMON_CTL3, MSR_UNC_C6_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX7C0", PMC40, CBOX7, MSR_UNC_C7_PMON_CTL0, MSR_UNC_C7_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX7C1", PMC41, CBOX7, MSR_UNC_C7_PMON_CTL1, MSR_UNC_C7_PMON_CTR1, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX7C2", PMC42, CBOX7, MSR_UNC_C7_PMON_CTL2, MSR_UNC_C7_PMON_CTR2, 0, 0, SNB_VALID_OPTIONS_CBOX},
    {"CBOX7C3", PMC43, CBOX7, MSR_UNC_C7_PMON_CTL3, MSR_UNC_C7_PMON_CTR3, 0, 0, SNB_VALID_OPTIONS_CBOX},
    /* UBOX counters */
    {"UBOX0", PMC44, UBOX, MSR_UNC_U_PMON_CTL0, MSR_UNC_U_PMON_CTR0, 0, 0, EVENT_OPTION_NONE_MASK},
    {"UBOX1", PMC45, UBOX, MSR_UNC_U_PMON_CTL1, MSR_UNC_U_PMON_CTR0, 0, 0, EVENT_OPTION_NONE_MASK},
    {"UBOXFIX", PMC46, UBOXFIX, MSR_UNC_U_UCLK_FIXED_CTL, MSR_UNC_U_UCLK_FIXED_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOX0",PMC47, WBOX, MSR_UNC_PCU_PMON_CTL0, MSR_UNC_PCU_PMON_CTR0, 0, 0, SNB_VALID_OPTIONS_WBOX},
    {"WBOXFIX0", PMC48, WBOX0FIX, 0, MSR_UNC_PCU_PMON_FIXED_CTR0, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOXFIX1", PMC49, WBOX0FIX, 0, MSR_UNC_PCU_PMON_FIXED_CTR1, 0, 0, EVENT_OPTION_NONE_MASK},
    /* IMC Counters: 4 48bit wide per memory channel, split in two reads */
    {"MBOX0C0",PMC50, MBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX0C1",PMC51, MBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX0C2",PMC52, MBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX0C3",PMC53, MBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX0FIX", PMC54, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX1C0",PMC55, MBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX1C1",PMC56, MBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX1C2",PMC57, MBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX1C3",PMC58, MBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX1FIX", PMC59, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX2C0",PMC60, MBOX2, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX2C1",PMC61, MBOX2, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX2C2",PMC62, MBOX2, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX2C3",PMC63, MBOX2, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX2FIX", PMC64, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX3C0",PMC65, MBOX3, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_NONE_MASK},
    {"MBOX3C1",PMC66, MBOX3, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_NONE_MASK},
    {"MBOX3C2",PMC67, MBOX3, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_NONE_MASK},
    {"MBOX3C3",PMC68, MBOX3, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_NONE_MASK},
    {"MBOX3FIX", PMC69, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_NONE_MASK},
    /* QPI counters four 48bit  wide per port, split in two reads */
    {"SBOX0C0",PMC70, SBOX0, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX0C1",PMC71, SBOX0, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX0C2",PMC72, SBOX0, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX0C3",PMC73, SBOX0, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX1C0",PMC74, SBOX1, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_1, EVENT_OPTION_NONE_MASK},
    {"SBOX1C1",PMC75, SBOX1, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_1, EVENT_OPTION_NONE_MASK},
    {"SBOX1C2",PMC76, SBOX1, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_1, EVENT_OPTION_NONE_MASK},
    {"SBOX1C3",PMC77, SBOX1, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_1, EVENT_OPTION_NONE_MASK},
    /* BBOX or better known as Home Agent (HA) */
    {"BBOX0",PMC78, BBOX0, PCI_UNC_HA_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_0, EVENT_OPTION_NONE_MASK},
    {"BBOX1",PMC79, BBOX0, PCI_UNC_HA_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_0, EVENT_OPTION_NONE_MASK},
    {"BBOX2",PMC80, BBOX0, PCI_UNC_HA_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_0, EVENT_OPTION_NONE_MASK},
    {"BBOX3",PMC81, BBOX0, PCI_UNC_HA_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C0", PMC82, RBOX0, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C1", PMC83, RBOX0, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_0, EVENT_OPTION_NONE_MASK},
    {"RBOX0C2", PMC84, RBOX0, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_0, EVENT_OPTION_NONE_MASK},
    {"RBOX1C0", PMC86, RBOX1, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_1, EVENT_OPTION_NONE_MASK},
    {"RBOX1C1", PMC87, RBOX1, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_1, EVENT_OPTION_NONE_MASK},
    {"RBOX1C2", PMC88, RBOX1, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_1, EVENT_OPTION_NONE_MASK},
    {"PBOX0", PMC89, PBOX, PCI_UNC_R2PCIE_PMON_CTL_0, PCI_UNC_R2PCIE_PMON_CTR_0_A, PCI_UNC_R2PCIE_PMON_CTR_0_B, PCI_R2PCIE_DEVICE, EVENT_OPTION_NONE_MASK},
    {"PBOX1", PMC90, PBOX, PCI_UNC_R2PCIE_PMON_CTL_1, PCI_UNC_R2PCIE_PMON_CTR_1_A, PCI_UNC_R2PCIE_PMON_CTR_1_B, PCI_R2PCIE_DEVICE, EVENT_OPTION_NONE_MASK},
    {"PBOX2", PMC91, PBOX, PCI_UNC_R2PCIE_PMON_CTL_2, PCI_UNC_R2PCIE_PMON_CTR_2_A, PCI_UNC_R2PCIE_PMON_CTR_2_B, PCI_R2PCIE_DEVICE, EVENT_OPTION_NONE_MASK},
    {"PBOX3", PMC92, PBOX, PCI_UNC_R2PCIE_PMON_CTL_3, PCI_UNC_R2PCIE_PMON_CTR_3_A, PCI_UNC_R2PCIE_PMON_CTR_3_B, PCI_R2PCIE_DEVICE, EVENT_OPTION_NONE_MASK},
};

static BoxMap sandybridgeEP_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, 0, 0, 48},
    [MBOX0] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX1] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX2] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX3] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [CBOX0] = {MSR_UNC_C0_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C0_PMON_BOX_FILTER},
    [CBOX1] = {MSR_UNC_C1_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C1_PMON_BOX_FILTER},
    [CBOX2] = {MSR_UNC_C2_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C2_PMON_BOX_FILTER},
    [CBOX3] = {MSR_UNC_C3_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C3_PMON_BOX_FILTER},
    [CBOX4] = {MSR_UNC_C4_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C4_PMON_BOX_FILTER},
    [CBOX5] = {MSR_UNC_C5_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C5_PMON_BOX_FILTER},
    [CBOX6] = {MSR_UNC_C6_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C6_PMON_BOX_FILTER},
    [CBOX7] = {MSR_UNC_C7_PMON_BOX_CTL, 0, 0, 0, 0, 44, MSR_UNC_C7_PMON_BOX_FILTER},
    [BBOX0] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 1, PCI_HA_DEVICE_0, 48},
    [BBOX1] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 1, PCI_HA_DEVICE_1, 48},
    [SBOX0] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 1, PCI_QPI_DEVICE_PORT_0, 48},
    [SBOX1] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 1, PCI_QPI_DEVICE_PORT_1, 48},
    [WBOX] = {MSR_UNC_PCU_PMON_BOX_CTL, MSR_UNC_PCU_PMON_BOX_STATUS, MSR_UNC_PCU_PMON_BOX_STATUS, 0, 0, 48},
    [UBOX] = {0, MSR_UNC_U_PMON_BOX_STATUS, 0, 0, 0, 44},
    [RBOX0] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 1, PCI_R3QPI_DEVICE_LINK_0, 44},
    [RBOX1] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 1, PCI_R3QPI_DEVICE_LINK_1, 44},
    [PBOX] = {PCI_UNC_R2PCIE_PMON_BOX_CTL, PCI_UNC_R2PCIE_PMON_BOX_STATUS, PCI_UNC_R2PCIE_PMON_BOX_STATUS, 1, PCI_R3QPI_DEVICE_LINK_1, 44},
};

static PciDevice sandybridgeEP_pci_devices[MAX_NUM_PCI_DEVICES] = {
 [MSR_DEV] = {NONE, "", "", ""},
 [PCI_R3QPI_DEVICE_LINK_0] = {R3QPI, "13.5", "PCI_R3QPI_DEVICE_LINK_0", "RBOX0", 0x3c44},
 [PCI_R3QPI_DEVICE_LINK_1] = {R3QPI, "13.6", "PCI_R3QPI_DEVICE_LINK_1", "RBOX1", 0x3c45},
 [PCI_R2PCIE_DEVICE] = {R2PCIE, "13.1", "PCI_R2PCIE_DEVICE", "PBOX0", 0x3c43},
 [PCI_IMC_DEVICE_0_CH_0] = {IMC, "10.0", "PCI_IMC_DEVICE_CH_0", "MBOX0", 0x3cb0},
 [PCI_IMC_DEVICE_0_CH_1] = {IMC, "10.1", "PCI_IMC_DEVICE_CH_1", "MBOX1", 0x3cb1},
 [PCI_IMC_DEVICE_0_CH_2] = {IMC, "10.4", "PCI_IMC_DEVICE_CH_2", "MBOX2", 0x3cb4},
 [PCI_IMC_DEVICE_0_CH_3] = {IMC, "10.5", "PCI_IMC_DEVICE_CH_3", "MBOX3", 0x3cb5},
 [PCI_HA_DEVICE_0] = {HA, "0e.1", "PCI_HA_DEVICE", "BBOX", 0x3c46},
 [PCI_QPI_DEVICE_PORT_0] = {QPI, "08.2", "PCI_QPI_DEVICE_PORT_0", "SBOX0", 0x3c41},
 [PCI_QPI_DEVICE_PORT_1] = {QPI, "09.2", "PCI_QPI_DEVICE_PORT_1", "SBOX1", 0x3c42},
 [PCI_QPI_MASK_DEVICE_PORT_0] = {QPI, "08.6", "PCI_QPI_MASK_DEVICE_PORT_0", NULL, 0x3c86},
 [PCI_QPI_MASK_DEVICE_PORT_1] = {QPI, "09.6", "PCI_QPI_MASK_DEVICE_PORT_1", NULL, 0x3c96},
 [PCI_QPI_MISC_DEVICE_PORT_0] = {QPI, "08.0", "PCI_QPI_MISC_DEVICE_PORT_0", "SBOX0FIX",0x3c80},
 [PCI_QPI_MISC_DEVICE_PORT_2] = {QPI, "09.0", "PCI_QPI_MISC_DEVICE_PORT_1", "SBOX1FIX", 0x3c91},
};

