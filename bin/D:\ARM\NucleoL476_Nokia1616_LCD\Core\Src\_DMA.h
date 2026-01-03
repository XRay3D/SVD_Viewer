#pragma once
#include <stdint.h>
#include <stm32l476xx.h>

#define MASK_TO_BIT31(A)    (A==0x80000000)? 31 : 0
#define MASK_TO_BIT30(A)    (A==0x40000000)? 30 : MASK_TO_BIT31(A)
#define MASK_TO_BIT29(A)    (A==0x20000000)? 29 : MASK_TO_BIT30(A)
#define MASK_TO_BIT28(A)    (A==0x10000000)? 28 : MASK_TO_BIT29(A)
#define MASK_TO_BIT27(A)    (A==0x08000000)? 27 : MASK_TO_BIT28(A)
#define MASK_TO_BIT26(A)    (A==0x04000000)? 26 : MASK_TO_BIT27(A)
#define MASK_TO_BIT25(A)    (A==0x02000000)? 25 : MASK_TO_BIT26(A)
#define MASK_TO_BIT24(A)    (A==0x01000000)? 24 : MASK_TO_BIT25(A)
#define MASK_TO_BIT23(A)    (A==0x00800000)? 23 : MASK_TO_BIT24(A)
#define MASK_TO_BIT22(A)    (A==0x00400000)? 22 : MASK_TO_BIT23(A)
#define MASK_TO_BIT21(A)    (A==0x00200000)? 21 : MASK_TO_BIT22(A)
#define MASK_TO_BIT20(A)    (A==0x00100000)? 20 : MASK_TO_BIT21(A)
#define MASK_TO_BIT19(A)    (A==0x00080000)? 19 : MASK_TO_BIT20(A)
#define MASK_TO_BIT18(A)    (A==0x00040000)? 18 : MASK_TO_BIT19(A)
#define MASK_TO_BIT17(A)    (A==0x00020000)? 17 : MASK_TO_BIT18(A)
#define MASK_TO_BIT16(A)    (A==0x00010000)? 16 : MASK_TO_BIT17(A)
#define MASK_TO_BIT15(A)    (A==0x00008000)? 15 : MASK_TO_BIT16(A)
#define MASK_TO_BIT14(A)    (A==0x00004000)? 14 : MASK_TO_BIT15(A)
#define MASK_TO_BIT13(A)    (A==0x00002000)? 13 : MASK_TO_BIT14(A)
#define MASK_TO_BIT12(A)    (A==0x00001000)? 12 : MASK_TO_BIT13(A)
#define MASK_TO_BIT11(A)    (A==0x00000800)? 11 : MASK_TO_BIT12(A)
#define MASK_TO_BIT10(A)    (A==0x00000400)? 10 : MASK_TO_BIT11(A)
#define MASK_TO_BIT09(A)    (A==0x00000200)? 9  : MASK_TO_BIT10(A)
#define MASK_TO_BIT08(A)    (A==0x00000100)? 8  : MASK_TO_BIT09(A)
#define MASK_TO_BIT07(A)    (A==0x00000080)? 7  : MASK_TO_BIT08(A)
#define MASK_TO_BIT06(A)    (A==0x00000040)? 6  : MASK_TO_BIT07(A)
#define MASK_TO_BIT05(A)    (A==0x00000020)? 5  : MASK_TO_BIT06(A)
#define MASK_TO_BIT04(A)    (A==0x00000010)? 4  : MASK_TO_BIT05(A)
#define MASK_TO_BIT03(A)    (A==0x00000008)? 3  : MASK_TO_BIT04(A)
#define MASK_TO_BIT02(A)    (A==0x00000004)? 2  : MASK_TO_BIT03(A)
#define MASK_TO_BIT01(A)    (A==0x00000002)? 1  : MASK_TO_BIT02(A)
#define MASK_TO_BIT00(A)    (A==0x00000001)? 0  : MASK_TO_BIT01(A)

#define BIT_BAND_PER(REG,BIT_MASK) (*(volatile uint32_t*)(PERIPH_BB_BASE+32*((uint32_t)(&(REG))-PERIPH_BASE)+4*((uint32_t)(MASK_TO_BIT00(BIT_MASK)))))
#define BIT_BAND_SRAM(RAM,BIT) (*(volatile uint32_t*)(SRAM_BB_BASE+32*((uint32_t)((void*)(RAM))-SRAM_BASE)+4*((uint32_t)(BIT))))

//Example: BIT_BAND_PER(TIM1->SR, TIM_SR_UIF) = 0; //сбросить бит TIM_SR_UIF в TIM1->SR
//Example2: BIT_BAND_SRAM(&a, 13) = 1; //установить 13-й бит в переменной "a"
//Example3: BIT_BAND_SRAM(&a, 13) ^= 1; //инвертировать 13-й бит в "a", не задевая другие биты переменной (псевдо-атомарность)
// description ['D', 'M', 'A', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r']
struct ['D', 'M', 'A']_ {
    class alignas(4) ['I', 'S', 'R']_ { // ['i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 's', 't', 'a', 't', 'u', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['G', 'I', 'F', '1']: ['1']; // bitOffset ['0', ' ', 'G', 'I', 'F', '1']
            unsigned ['T', 'C', 'I', 'F', '1']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'F', '1']
            unsigned ['H', 'T', 'I', 'F', '1']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'F', '1']
            unsigned ['T', 'E', 'I', 'F', '1']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'F', '1']
            unsigned ['G', 'I', 'F', '2']: ['1']; // bitOffset ['4', ' ', 'G', 'I', 'F', '2']
            unsigned ['T', 'C', 'I', 'F', '2']: ['1']; // bitOffset ['5', ' ', 'T', 'C', 'I', 'F', '2']
            unsigned ['H', 'T', 'I', 'F', '2']: ['1']; // bitOffset ['6', ' ', 'H', 'T', 'I', 'F', '2']
            unsigned ['T', 'E', 'I', 'F', '2']: ['1']; // bitOffset ['7', ' ', 'T', 'E', 'I', 'F', '2']
            unsigned ['G', 'I', 'F', '3']: ['1']; // bitOffset ['8', ' ', 'G', 'I', 'F', '3']
            unsigned ['T', 'C', 'I', 'F', '3']: ['1']; // bitOffset ['9', ' ', 'T', 'C', 'I', 'F', '3']
            unsigned ['H', 'T', 'I', 'F', '3']: ['1']; // bitOffset ['1', '0', ' ', 'H', 'T', 'I', 'F', '3']
            unsigned ['T', 'E', 'I', 'F', '3']: ['1']; // bitOffset ['1', '1', ' ', 'T', 'E', 'I', 'F', '3']
            unsigned ['G', 'I', 'F', '4']: ['1']; // bitOffset ['1', '2', ' ', 'G', 'I', 'F', '4']
            unsigned ['T', 'C', 'I', 'F', '4']: ['1']; // bitOffset ['1', '3', ' ', 'T', 'C', 'I', 'F', '4']
            unsigned ['H', 'T', 'I', 'F', '4']: ['1']; // bitOffset ['1', '4', ' ', 'H', 'T', 'I', 'F', '4']
            unsigned ['T', 'E', 'I', 'F', '4']: ['1']; // bitOffset ['1', '5', ' ', 'T', 'E', 'I', 'F', '4']
            unsigned ['G', 'I', 'F', '5']: ['1']; // bitOffset ['1', '6', ' ', 'G', 'I', 'F', '5']
            unsigned ['T', 'C', 'I', 'F', '5']: ['1']; // bitOffset ['1', '7', ' ', 'T', 'C', 'I', 'F', '5']
            unsigned ['H', 'T', 'I', 'F', '5']: ['1']; // bitOffset ['1', '8', ' ', 'H', 'T', 'I', 'F', '5']
            unsigned ['T', 'E', 'I', 'F', '5']: ['1']; // bitOffset ['1', '9', ' ', 'T', 'E', 'I', 'F', '5']
            unsigned ['G', 'I', 'F', '6']: ['1']; // bitOffset ['2', '0', ' ', 'G', 'I', 'F', '6']
            unsigned ['T', 'C', 'I', 'F', '6']: ['1']; // bitOffset ['2', '1', ' ', 'T', 'C', 'I', 'F', '6']
            unsigned ['H', 'T', 'I', 'F', '6']: ['1']; // bitOffset ['2', '2', ' ', 'H', 'T', 'I', 'F', '6']
            unsigned ['T', 'E', 'I', 'F', '6']: ['1']; // bitOffset ['2', '3', ' ', 'T', 'E', 'I', 'F', '6']
            unsigned ['G', 'I', 'F', '7']: ['1']; // bitOffset ['2', '4', ' ', 'G', 'I', 'F', '7']
            unsigned ['T', 'C', 'I', 'F', '7']: ['1']; // bitOffset ['2', '5', ' ', 'T', 'C', 'I', 'F', '7']
            unsigned ['H', 'T', 'I', 'F', '7']: ['1']; // bitOffset ['2', '6', ' ', 'H', 'T', 'I', 'F', '7']
            unsigned ['T', 'E', 'I', 'F', '7']: ['1']; // bitOffset ['2', '7', ' ', 'T', 'E', 'I', 'F', '7']
            unsigned ['G', 'I', 'F', '8']: ['1']; // bitOffset ['2', '8', ' ', 'G', 'I', 'F', '8']
            unsigned ['T', 'C', 'I', 'F', '8']: ['1']; // bitOffset ['2', '9', ' ', 'T', 'C', 'I', 'F', '8']
            unsigned ['H', 'T', 'I', 'F', '8']: ['1']; // bitOffset ['3', '0', ' ', 'H', 'T', 'I', 'F', '8']
            unsigned ['T', 'E', 'I', 'F', '8']: ['1']; // bitOffset ['3', '1', ' ', 'T', 'E', 'I', 'F', '8']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['G', 'I', 'F', '1'] */
        auto ['G', 'I', 'F', '1']() const { return BIT_BAND_PER(U.U32, 1 << ['0']); }
        /** @brief ['T', 'C', 'I', 'F', '1'] */
        auto ['T', 'C', 'I', 'F', '1']() const { return BIT_BAND_PER(U.U32, 1 << ['1']); }
        /** @brief ['H', 'T', 'I', 'F', '1'] */
        auto ['H', 'T', 'I', 'F', '1']() const { return BIT_BAND_PER(U.U32, 1 << ['2']); }
        /** @brief ['T', 'E', 'I', 'F', '1'] */
        auto ['T', 'E', 'I', 'F', '1']() const { return BIT_BAND_PER(U.U32, 1 << ['3']); }
        /** @brief ['G', 'I', 'F', '2'] */
        auto ['G', 'I', 'F', '2']() const { return BIT_BAND_PER(U.U32, 1 << ['4']); }
        /** @brief ['T', 'C', 'I', 'F', '2'] */
        auto ['T', 'C', 'I', 'F', '2']() const { return BIT_BAND_PER(U.U32, 1 << ['5']); }
        /** @brief ['H', 'T', 'I', 'F', '2'] */
        auto ['H', 'T', 'I', 'F', '2']() const { return BIT_BAND_PER(U.U32, 1 << ['6']); }
        /** @brief ['T', 'E', 'I', 'F', '2'] */
        auto ['T', 'E', 'I', 'F', '2']() const { return BIT_BAND_PER(U.U32, 1 << ['7']); }
        /** @brief ['G', 'I', 'F', '3'] */
        auto ['G', 'I', 'F', '3']() const { return BIT_BAND_PER(U.U32, 1 << ['8']); }
        /** @brief ['T', 'C', 'I', 'F', '3'] */
        auto ['T', 'C', 'I', 'F', '3']() const { return BIT_BAND_PER(U.U32, 1 << ['9']); }
        /** @brief ['H', 'T', 'I', 'F', '3'] */
        auto ['H', 'T', 'I', 'F', '3']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '0']); }
        /** @brief ['T', 'E', 'I', 'F', '3'] */
        auto ['T', 'E', 'I', 'F', '3']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '1']); }
        /** @brief ['G', 'I', 'F', '4'] */
        auto ['G', 'I', 'F', '4']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '2']); }
        /** @brief ['T', 'C', 'I', 'F', '4'] */
        auto ['T', 'C', 'I', 'F', '4']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '3']); }
        /** @brief ['H', 'T', 'I', 'F', '4'] */
        auto ['H', 'T', 'I', 'F', '4']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '4']); }
        /** @brief ['T', 'E', 'I', 'F', '4'] */
        auto ['T', 'E', 'I', 'F', '4']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '5']); }
        /** @brief ['G', 'I', 'F', '5'] */
        auto ['G', 'I', 'F', '5']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '6']); }
        /** @brief ['T', 'C', 'I', 'F', '5'] */
        auto ['T', 'C', 'I', 'F', '5']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '7']); }
        /** @brief ['H', 'T', 'I', 'F', '5'] */
        auto ['H', 'T', 'I', 'F', '5']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '8']); }
        /** @brief ['T', 'E', 'I', 'F', '5'] */
        auto ['T', 'E', 'I', 'F', '5']() const { return BIT_BAND_PER(U.U32, 1 << ['1', '9']); }
        /** @brief ['G', 'I', 'F', '6'] */
        auto ['G', 'I', 'F', '6']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '0']); }
        /** @brief ['T', 'C', 'I', 'F', '6'] */
        auto ['T', 'C', 'I', 'F', '6']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '1']); }
        /** @brief ['H', 'T', 'I', 'F', '6'] */
        auto ['H', 'T', 'I', 'F', '6']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '2']); }
        /** @brief ['T', 'E', 'I', 'F', '6'] */
        auto ['T', 'E', 'I', 'F', '6']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '3']); }
        /** @brief ['G', 'I', 'F', '7'] */
        auto ['G', 'I', 'F', '7']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '4']); }
        /** @brief ['T', 'C', 'I', 'F', '7'] */
        auto ['T', 'C', 'I', 'F', '7']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '5']); }
        /** @brief ['H', 'T', 'I', 'F', '7'] */
        auto ['H', 'T', 'I', 'F', '7']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '6']); }
        /** @brief ['T', 'E', 'I', 'F', '7'] */
        auto ['T', 'E', 'I', 'F', '7']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '7']); }
        /** @brief ['G', 'I', 'F', '8'] */
        auto ['G', 'I', 'F', '8']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '8']); }
        /** @brief ['T', 'C', 'I', 'F', '8'] */
        auto ['T', 'C', 'I', 'F', '8']() const { return BIT_BAND_PER(U.U32, 1 << ['2', '9']); }
        /** @brief ['H', 'T', 'I', 'F', '8'] */
        auto ['H', 'T', 'I', 'F', '8']() const { return BIT_BAND_PER(U.U32, 1 << ['3', '0']); }
        /** @brief ['T', 'E', 'I', 'F', '8'] */
        auto ['T', 'E', 'I', 'F', '8']() const { return BIT_BAND_PER(U.U32, 1 << ['3', '1']); }
    };
    class alignas(4) ['I', 'F', 'C', 'R']_ { // ['D', 'M', 'A', ' ', 'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'f', 'l', 'a', 'g', ' ', 'c', 'l', 'e', 'a', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['G', 'I', 'F', '1']: ['1']; // bitOffset ['0', ' ', 'G', 'I', 'F', '1']
            unsigned ['T', 'C', 'I', 'F', '1']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'F', '1']
            unsigned ['H', 'T', 'I', 'F', '1']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'F', '1']
            unsigned ['T', 'E', 'I', 'F', '1']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'F', '1']
            unsigned ['G', 'I', 'F', '2']: ['1']; // bitOffset ['4', ' ', 'G', 'I', 'F', '2']
            unsigned ['T', 'C', 'I', 'F', '2']: ['1']; // bitOffset ['5', ' ', 'T', 'C', 'I', 'F', '2']
            unsigned ['H', 'T', 'I', 'F', '2']: ['1']; // bitOffset ['6', ' ', 'H', 'T', 'I', 'F', '2']
            unsigned ['T', 'E', 'I', 'F', '2']: ['1']; // bitOffset ['7', ' ', 'T', 'E', 'I', 'F', '2']
            unsigned ['G', 'I', 'F', '3']: ['1']; // bitOffset ['8', ' ', 'G', 'I', 'F', '3']
            unsigned ['T', 'C', 'I', 'F', '3']: ['1']; // bitOffset ['9', ' ', 'T', 'C', 'I', 'F', '3']
            unsigned ['H', 'T', 'I', 'F', '3']: ['1']; // bitOffset ['1', '0', ' ', 'H', 'T', 'I', 'F', '3']
            unsigned ['T', 'E', 'I', 'F', '3']: ['1']; // bitOffset ['1', '1', ' ', 'T', 'E', 'I', 'F', '3']
            unsigned ['G', 'I', 'F', '4']: ['1']; // bitOffset ['1', '2', ' ', 'G', 'I', 'F', '4']
            unsigned ['T', 'C', 'I', 'F', '4']: ['1']; // bitOffset ['1', '3', ' ', 'T', 'C', 'I', 'F', '4']
            unsigned ['H', 'T', 'I', 'F', '4']: ['1']; // bitOffset ['1', '4', ' ', 'H', 'T', 'I', 'F', '4']
            unsigned ['T', 'E', 'I', 'F', '4']: ['1']; // bitOffset ['1', '5', ' ', 'T', 'E', 'I', 'F', '4']
            unsigned ['G', 'I', 'F', '5']: ['1']; // bitOffset ['1', '6', ' ', 'G', 'I', 'F', '5']
            unsigned ['T', 'C', 'I', 'F', '5']: ['1']; // bitOffset ['1', '7', ' ', 'T', 'C', 'I', 'F', '5']
            unsigned ['H', 'T', 'I', 'F', '5']: ['1']; // bitOffset ['1', '8', ' ', 'H', 'T', 'I', 'F', '5']
            unsigned ['T', 'E', 'I', 'F', '5']: ['1']; // bitOffset ['1', '9', ' ', 'T', 'E', 'I', 'F', '5']
            unsigned ['G', 'I', 'F', '6']: ['1']; // bitOffset ['2', '0', ' ', 'G', 'I', 'F', '6']
            unsigned ['T', 'C', 'I', 'F', '6']: ['1']; // bitOffset ['2', '1', ' ', 'T', 'C', 'I', 'F', '6']
            unsigned ['H', 'T', 'I', 'F', '6']: ['1']; // bitOffset ['2', '2', ' ', 'H', 'T', 'I', 'F', '6']
            unsigned ['T', 'E', 'I', 'F', '6']: ['1']; // bitOffset ['2', '3', ' ', 'T', 'E', 'I', 'F', '6']
            unsigned ['G', 'I', 'F', '7']: ['1']; // bitOffset ['2', '4', ' ', 'G', 'I', 'F', '7']
            unsigned ['T', 'C', 'I', 'F', '7']: ['1']; // bitOffset ['2', '5', ' ', 'T', 'C', 'I', 'F', '7']
            unsigned ['H', 'T', 'I', 'F', '7']: ['1']; // bitOffset ['2', '6', ' ', 'H', 'T', 'I', 'F', '7']
            unsigned ['T', 'E', 'I', 'F', '7']: ['1']; // bitOffset ['2', '7', ' ', 'T', 'E', 'I', 'F', '7']
            unsigned ['G', 'I', 'F', '8']: ['1']; // bitOffset ['2', '8', ' ', 'G', 'I', 'F', '8']
            unsigned ['T', 'C', 'I', 'F', '8']: ['1']; // bitOffset ['2', '9', ' ', 'T', 'C', 'I', 'F', '8']
            unsigned ['H', 'T', 'I', 'F', '8']: ['1']; // bitOffset ['3', '0', ' ', 'H', 'T', 'I', 'F', '8']
            unsigned ['T', 'E', 'I', 'F', '8']: ['1']; // bitOffset ['3', '1', ' ', 'T', 'E', 'I', 'F', '8']
            };
            uint32_t U32;
        } U;
    public:
        /** @brief ['G', 'I', 'F', '1'] */
        void ['G', 'I', 'F', '1']() volatile { U.['G', 'I', 'F', '1'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '1'] */
        void ['T', 'C', 'I', 'F', '1']() volatile { U.['T', 'C', 'I', 'F', '1'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '1'] */
        void ['H', 'T', 'I', 'F', '1']() volatile { U.['H', 'T', 'I', 'F', '1'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '1'] */
        void ['T', 'E', 'I', 'F', '1']() volatile { U.['T', 'E', 'I', 'F', '1'] = 1; }
        /** @brief ['G', 'I', 'F', '2'] */
        void ['G', 'I', 'F', '2']() volatile { U.['G', 'I', 'F', '2'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '2'] */
        void ['T', 'C', 'I', 'F', '2']() volatile { U.['T', 'C', 'I', 'F', '2'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '2'] */
        void ['H', 'T', 'I', 'F', '2']() volatile { U.['H', 'T', 'I', 'F', '2'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '2'] */
        void ['T', 'E', 'I', 'F', '2']() volatile { U.['T', 'E', 'I', 'F', '2'] = 1; }
        /** @brief ['G', 'I', 'F', '3'] */
        void ['G', 'I', 'F', '3']() volatile { U.['G', 'I', 'F', '3'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '3'] */
        void ['T', 'C', 'I', 'F', '3']() volatile { U.['T', 'C', 'I', 'F', '3'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '3'] */
        void ['H', 'T', 'I', 'F', '3']() volatile { U.['H', 'T', 'I', 'F', '3'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '3'] */
        void ['T', 'E', 'I', 'F', '3']() volatile { U.['T', 'E', 'I', 'F', '3'] = 1; }
        /** @brief ['G', 'I', 'F', '4'] */
        void ['G', 'I', 'F', '4']() volatile { U.['G', 'I', 'F', '4'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '4'] */
        void ['T', 'C', 'I', 'F', '4']() volatile { U.['T', 'C', 'I', 'F', '4'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '4'] */
        void ['H', 'T', 'I', 'F', '4']() volatile { U.['H', 'T', 'I', 'F', '4'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '4'] */
        void ['T', 'E', 'I', 'F', '4']() volatile { U.['T', 'E', 'I', 'F', '4'] = 1; }
        /** @brief ['G', 'I', 'F', '5'] */
        void ['G', 'I', 'F', '5']() volatile { U.['G', 'I', 'F', '5'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '5'] */
        void ['T', 'C', 'I', 'F', '5']() volatile { U.['T', 'C', 'I', 'F', '5'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '5'] */
        void ['H', 'T', 'I', 'F', '5']() volatile { U.['H', 'T', 'I', 'F', '5'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '5'] */
        void ['T', 'E', 'I', 'F', '5']() volatile { U.['T', 'E', 'I', 'F', '5'] = 1; }
        /** @brief ['G', 'I', 'F', '6'] */
        void ['G', 'I', 'F', '6']() volatile { U.['G', 'I', 'F', '6'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '6'] */
        void ['T', 'C', 'I', 'F', '6']() volatile { U.['T', 'C', 'I', 'F', '6'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '6'] */
        void ['H', 'T', 'I', 'F', '6']() volatile { U.['H', 'T', 'I', 'F', '6'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '6'] */
        void ['T', 'E', 'I', 'F', '6']() volatile { U.['T', 'E', 'I', 'F', '6'] = 1; }
        /** @brief ['G', 'I', 'F', '7'] */
        void ['G', 'I', 'F', '7']() volatile { U.['G', 'I', 'F', '7'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '7'] */
        void ['T', 'C', 'I', 'F', '7']() volatile { U.['T', 'C', 'I', 'F', '7'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '7'] */
        void ['H', 'T', 'I', 'F', '7']() volatile { U.['H', 'T', 'I', 'F', '7'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '7'] */
        void ['T', 'E', 'I', 'F', '7']() volatile { U.['T', 'E', 'I', 'F', '7'] = 1; }
        /** @brief ['G', 'I', 'F', '8'] */
        void ['G', 'I', 'F', '8']() volatile { U.['G', 'I', 'F', '8'] = 1; }
        /** @brief ['T', 'C', 'I', 'F', '8'] */
        void ['T', 'C', 'I', 'F', '8']() volatile { U.['T', 'C', 'I', 'F', '8'] = 1; }
        /** @brief ['H', 'T', 'I', 'F', '8'] */
        void ['H', 'T', 'I', 'F', '8']() volatile { U.['H', 'T', 'I', 'F', '8'] = 1; }
        /** @brief ['T', 'E', 'I', 'F', '8'] */
        void ['T', 'E', 'I', 'F', '8']() volatile { U.['T', 'E', 'I', 'F', '8'] = 1; }
    };
    class alignas(4) ['C', 'C', 'R', '1']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '1', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '1']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '1']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '1']_ = uint32_t;
    class alignas(4) ['C', 'C', 'R', '2']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '2', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '2']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '2']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '2']_ = uint32_t;
    class alignas(4) ['C', 'C', 'R', '3']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '3', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '3']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '3']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '3']_ = uint32_t;
    class alignas(4) ['C', 'C', 'R', '4']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '3', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '4']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '4']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '4']_ = uint32_t;
    class alignas(4) ['C', 'C', 'R', '5']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '4', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '5']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '5']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '5']_ = uint32_t;
    class alignas(4) ['C', 'C', 'R', '6']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '5', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '6']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '6']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '6']_ = uint32_t;
    class alignas(4) ['C', 'C', 'R', '7']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '6', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '7']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '7']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '7']_ = uint32_t;
    class alignas(4) ['C', 'C', 'R', '8']_ { // ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '7', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['E', 'N']: ['1']; // bitOffset ['0', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e']
            unsigned ['T', 'C', 'I', 'E']: ['1']; // bitOffset ['1', ' ', 'T', 'C', 'I', 'E']
            unsigned ['H', 'T', 'I', 'E']: ['1']; // bitOffset ['2', ' ', 'H', 'T', 'I', 'E']
            unsigned ['T', 'E', 'I', 'E']: ['1']; // bitOffset ['3', ' ', 'T', 'E', 'I', 'E']
            unsigned ['D', 'I', 'R']: ['1']; // bitOffset ['4', ' ', 'D', 'I', 'R']
            unsigned ['C', 'I', 'R', 'C']: ['1']; // bitOffset ['5', ' ', 'C', 'I', 'R', 'C']
            unsigned ['P', 'I', 'N', 'C']: ['1']; // bitOffset ['6', ' ', 'P', 'I', 'N', 'C']
            unsigned ['M', 'I', 'N', 'C']: ['1']; // bitOffset ['7', ' ', 'M', 'I', 'N', 'C']
            unsigned ['P', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['8', ' ', 'P', 'S', 'I', 'Z', 'E']
            unsigned ['M', 'S', 'I', 'Z', 'E']: ['2']; // bitOffset ['1', '0', ' ', 'M', 'S', 'I', 'Z', 'E']
            unsigned ['P', 'L']: ['2']; // bitOffset ['1', '2', ' ', 'P', 'L']
            unsigned ['M', 'E', 'M', '2', 'M', 'E', 'M']: ['1']; // bitOffset ['1', '4', ' ', 'M', 'E', 'M', '2', 'M', 'E', 'M']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        auto ['E', 'N']() const { return U.['E', 'N']; }
        /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e'] */
        void ['E', 'N'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['0']) = fl; }
        /** @brief ['T', 'C', 'I', 'E'] */
        auto ['T', 'C', 'I', 'E']() const { return U.['T', 'C', 'I', 'E']; }
        /** @brief ['T', 'C', 'I', 'E'] */
        void ['T', 'C', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1']) = fl; }
        /** @brief ['H', 'T', 'I', 'E'] */
        auto ['H', 'T', 'I', 'E']() const { return U.['H', 'T', 'I', 'E']; }
        /** @brief ['H', 'T', 'I', 'E'] */
        void ['H', 'T', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['2']) = fl; }
        /** @brief ['T', 'E', 'I', 'E'] */
        auto ['T', 'E', 'I', 'E']() const { return U.['T', 'E', 'I', 'E']; }
        /** @brief ['T', 'E', 'I', 'E'] */
        void ['T', 'E', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['3']) = fl; }
        /** @brief ['D', 'I', 'R'] */
        auto ['D', 'I', 'R']() const { return U.['D', 'I', 'R']; }
        /** @brief ['D', 'I', 'R'] */
        void ['D', 'I', 'R'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['4']) = fl; }
        /** @brief ['C', 'I', 'R', 'C'] */
        auto ['C', 'I', 'R', 'C']() const { return U.['C', 'I', 'R', 'C']; }
        /** @brief ['C', 'I', 'R', 'C'] */
        void ['C', 'I', 'R', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['5']) = fl; }
        /** @brief ['P', 'I', 'N', 'C'] */
        auto ['P', 'I', 'N', 'C']() const { return U.['P', 'I', 'N', 'C']; }
        /** @brief ['P', 'I', 'N', 'C'] */
        void ['P', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['6']) = fl; }
        /** @brief ['M', 'I', 'N', 'C'] */
        auto ['M', 'I', 'N', 'C']() const { return U.['M', 'I', 'N', 'C']; }
        /** @brief ['M', 'I', 'N', 'C'] */
        void ['M', 'I', 'N', 'C'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['7']) = fl; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        auto ['P', 'S', 'I', 'Z', 'E']() const { return U.['P', 'S', 'I', 'Z', 'E']; }
        /** @brief ['P', 'S', 'I', 'Z', 'E'] */
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        void ['P', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['8']); }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        auto ['M', 'S', 'I', 'Z', 'E']() const { return U.['M', 'S', 'I', 'Z', 'E']; }
        /** @brief ['M', 'S', 'I', 'Z', 'E'] */
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        void ['M', 'S', 'I', 'Z', 'E'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '0']); }
        /** @brief ['P', 'L'] */
        auto ['P', 'L']() const { return U.['P', 'L']; }
        /** @brief ['P', 'L'] */
        void ['P', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        void ['P', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '2']); }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        auto ['M', 'E', 'M', '2', 'M', 'E', 'M']() const { return U.['M', 'E', 'M', '2', 'M', 'E', 'M']; }
        /** @brief ['M', 'E', 'M', '2', 'M', 'E', 'M'] */
        void ['M', 'E', 'M', '2', 'M', 'E', 'M'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '4']) = fl; }
    };
    class alignas(4) ['C', 'N', 'D', 'T', 'R', '8']_ { // ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['N', 'D', 'T']: ['1', '6']; // bitOffset ['0', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        auto ['N', 'D', 'T']() const { return U.['N', 'D', 'T']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 'i', 't', 'e', 'm', 's', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'] */
        void ['N', 'D', 'T'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['N', 'D', 'T'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
    };
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'P', 'A', 'R', '8']_ = uint32_t;
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    using ['C', 'M', 'A', 'R', '8']_ = uint32_t;

    /** @brief ['i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 's', 't', 'a', 't', 'u', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['I', 'S', 'R']_ ['I', 'S', 'R'];
    /** @brief ['D', 'M', 'A', ' ', 'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'f', 'l', 'a', 'g', ' ', 'c', 'l', 'e', 'a', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['I', 'F', 'C', 'R']_ ['I', 'F', 'C', 'R'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '1', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '1']_ ['C', 'C', 'R', '1'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '1']_ ['C', 'N', 'D', 'T', 'R', '1'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '1']_ ['C', 'P', 'A', 'R', '1'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '1']_ ['C', 'M', 'A', 'R', '1'];
    uint32_t padding24[1];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '2', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '2']_ ['C', 'C', 'R', '2'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '2']_ ['C', 'N', 'D', 'T', 'R', '2'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '2']_ ['C', 'P', 'A', 'R', '2'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '2']_ ['C', 'M', 'A', 'R', '2'];
    uint32_t padding44[1];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '3', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '3']_ ['C', 'C', 'R', '3'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '3']_ ['C', 'N', 'D', 'T', 'R', '3'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '3']_ ['C', 'P', 'A', 'R', '3'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '3']_ ['C', 'M', 'A', 'R', '3'];
    uint32_t padding64[1];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '3', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '4']_ ['C', 'C', 'R', '4'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '4']_ ['C', 'N', 'D', 'T', 'R', '4'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '4']_ ['C', 'P', 'A', 'R', '4'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '4']_ ['C', 'M', 'A', 'R', '4'];
    uint32_t padding84[1];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '4', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '5']_ ['C', 'C', 'R', '5'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '5']_ ['C', 'N', 'D', 'T', 'R', '5'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '5']_ ['C', 'P', 'A', 'R', '5'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '5']_ ['C', 'M', 'A', 'R', '5'];
    uint32_t padding104[1];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '5', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '6']_ ['C', 'C', 'R', '6'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '6']_ ['C', 'N', 'D', 'T', 'R', '6'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '6']_ ['C', 'P', 'A', 'R', '6'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '6']_ ['C', 'M', 'A', 'R', '6'];
    uint32_t padding124[1];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '6', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '7']_ ['C', 'C', 'R', '7'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '7']_ ['C', 'N', 'D', 'T', 'R', '7'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '7']_ ['C', 'P', 'A', 'R', '7'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '7']_ ['C', 'M', 'A', 'R', '7'];
    uint32_t padding144[1];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', '7', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'C', 'R', '8']_ ['C', 'C', 'R', '8'];
    /** @brief ['c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'N', 'D', 'T', 'R', '8']_ ['C', 'N', 'D', 'T', 'R', '8'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'p', 'e', 'r', 'i', 'p', 'h', 'e', 'r', 'a', 'l', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'P', 'A', 'R', '8']_ ['C', 'P', 'A', 'R', '8'];
    /** @brief ['D', 'M', 'A', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'm', 'e', 'm', 'o', 'r', 'y', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'M', 'A', 'R', '8']_ ['C', 'M', 'A', 'R', '8'];
};

inline volatile ['D', 'M', 'A']_ _['D', 'M', 'A', '1'] = *reinterpret_cast<['D', 'M', 'A']_*>(['0', 'x', '4', '0', '0', '2', '0', '0', '0', '0']);
inline volatile ['D', 'M', 'A']_ _['D', 'M', 'A', '2'] = *reinterpret_cast<['D', 'M', 'A']_*>(['0', 'x', '4', '0', '0', '2', '0', '4', '0', '0']);
// description ['D', 'M', 'A', 'M', 'U', 'X']
struct ['D', 'M', 'A', 'M', 'U', 'X']_ {
    class alignas(4) ['C', '0', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '1', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '2', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '3', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '4', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '5', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '6', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '7', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '8', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '9', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '1', '0', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '1', '1', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '1', '2', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '1', '3', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '1', '4', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', '1', '5', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']: ['7']; // bitOffset ['0', ' ', 'I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 1;// Reserved / Unused
            unsigned ['S', 'O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
            unsigned ['E', 'G', 'E']: ['1']; // bitOffset ['9', ' ', 'E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
        unsigned : 6;// Reserved / Unused
            unsigned ['S', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['S', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':']
            unsigned ['N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.']
            unsigned ['S', 'Y', 'N', 'C', '_', 'I', 'D']: ['5']; // bitOffset ['2', '4', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']() const { return U.['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D']; }
        /** @brief ['I', 'n', 'p', 'u', 't', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['D', 'M', 'A', 'R', 'E', 'Q', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['S', 'O', 'I', 'E']() const { return U.['S', 'O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['S', 'O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['E', 'G', 'E']() const { return U.['E', 'G', 'E']; }
        /** @brief ['E', 'v', 'e', 'n', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['E', 'G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['9']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['S', 'E']() const { return U.['S', 'E']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['S', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        auto ['S', 'P', 'O', 'L']() const { return U.['S', 'P', 'O', 'L']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'o', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ':'] */
        void ['S', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['S', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['N', 'B', 'R', 'E', 'Q']() const { return U.['N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'o', 'u', 't', 'p', 'u', 't', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'i', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', '.', ' ', 'I', 'n', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'o', 'u', 's', ' ', 'm', 'o', 'd', 'e', ',', ' ', 'i', 't', ' ', 'a', 'l', 's', 'o', ' ', 'd', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'f', 'o', 'r', 'w', 'a', 'r', 'd', 'e', 'd', ' ', 'i', 's', ' ', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'b', 'o', 't', 'h', ' ', 'S', 'E', ' ', 'a', 'n', 'd', ' ', 'E', 'G', 'E', ' ', 'b', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'Y', 'N', 'C', '_', 'I', 'D']() const { return U.['S', 'Y', 'N', 'C', '_', 'I', 'D']; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
        void ['S', 'Y', 'N', 'C', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['2', '4']); }
    };
    class alignas(4) ['C', 'S', 'R']_ { // ['D', 'M', 'A', 'M', 'U', 'X', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 's', 't', 'a', 't', 'u', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['S', 'O', 'F']: ['1', '6']; // bitOffset ['0', ' ', 'S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'f', 'l', 'a', 'g']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['S', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'f', 'l', 'a', 'g'] */
        auto ['S', 'O', 'F']() const { return BIT_BAND_PER(U.U32, 1 << ['0']); }
    };
    class alignas(4) ['C', 'F', 'R']_ { // ['D', 'M', 'A', 'M', 'U', 'X', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'c', 'l', 'e', 'a', 'r', ' ', 'f', 'l', 'a', 'g', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['C', 'S', 'O', 'F']: ['1', '6']; // bitOffset ['0', ' ', 'C', 'l', 'e', 'a', 'r', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'f', 'l', 'a', 'g']
            };
            uint32_t U32;
        } U;
    public:
        /** @brief ['C', 'l', 'e', 'a', 'r', ' ', 's', 'y', 'n', 'c', 'h', 'r', 'o', 'n', 'i', 'z', 'a', 't', 'i', 'o', 'n', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'f', 'l', 'a', 'g'] */
    };
    class alignas(4) ['R', 'G', '0', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['S', 'I', 'G', '_', 'I', 'D']: ['5']; // bitOffset ['0', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 3;// Reserved / Unused
            unsigned ['O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
        unsigned : 7;// Reserved / Unused
            unsigned ['G', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['G', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't']
            unsigned ['G', 'N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'I', 'G', '_', 'I', 'D']() const { return U.['S', 'I', 'G', '_', 'I', 'D']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['O', 'I', 'E']() const { return U.['O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['G', 'E']() const { return U.['G', 'E']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        auto ['G', 'P', 'O', 'L']() const { return U.['G', 'P', 'O', 'L']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        void ['G', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['G', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['G', 'N', 'B', 'R', 'E', 'Q']() const { return U.['G', 'N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
    };
    class alignas(4) ['R', 'G', '1', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['S', 'I', 'G', '_', 'I', 'D']: ['5']; // bitOffset ['0', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 3;// Reserved / Unused
            unsigned ['O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
        unsigned : 7;// Reserved / Unused
            unsigned ['G', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['G', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't']
            unsigned ['G', 'N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'I', 'G', '_', 'I', 'D']() const { return U.['S', 'I', 'G', '_', 'I', 'D']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['O', 'I', 'E']() const { return U.['O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['G', 'E']() const { return U.['G', 'E']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        auto ['G', 'P', 'O', 'L']() const { return U.['G', 'P', 'O', 'L']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        void ['G', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['G', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['G', 'N', 'B', 'R', 'E', 'Q']() const { return U.['G', 'N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
    };
    class alignas(4) ['R', 'G', '2', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['S', 'I', 'G', '_', 'I', 'D']: ['5']; // bitOffset ['0', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 3;// Reserved / Unused
            unsigned ['O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
        unsigned : 7;// Reserved / Unused
            unsigned ['G', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['G', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't']
            unsigned ['G', 'N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'I', 'G', '_', 'I', 'D']() const { return U.['S', 'I', 'G', '_', 'I', 'D']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['O', 'I', 'E']() const { return U.['O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['G', 'E']() const { return U.['G', 'E']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        auto ['G', 'P', 'O', 'L']() const { return U.['G', 'P', 'O', 'L']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        void ['G', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['G', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['G', 'N', 'B', 'R', 'E', 'Q']() const { return U.['G', 'N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
    };
    class alignas(4) ['R', 'G', '3', 'C', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['S', 'I', 'G', '_', 'I', 'D']: ['5']; // bitOffset ['0', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd']
        unsigned : 3;// Reserved / Unused
            unsigned ['O', 'I', 'E']: ['1']; // bitOffset ['8', ' ', 'I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n']
        unsigned : 7;// Reserved / Unused
            unsigned ['G', 'E']: ['1']; // bitOffset ['1', '6', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e']
            unsigned ['G', 'P', 'O', 'L']: ['2']; // bitOffset ['1', '7', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't']
            unsigned ['G', 'N', 'B', 'R', 'E', 'Q']: ['5']; // bitOffset ['1', '9', ' ', 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        auto ['S', 'I', 'G', '_', 'I', 'D']() const { return U.['S', 'I', 'G', '_', 'I', 'D']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd'] */
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        void ['S', 'I', 'G', '_', 'I', 'D'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1']) | (val << ['0']); }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        auto ['O', 'I', 'E']() const { return U.['O', 'I', 'E']; }
        /** @brief ['I', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'e', 'n', 'a', 'b', 'l', 'e', ' ', 'a', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n'] */
        void ['O', 'I', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['8']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        auto ['G', 'E']() const { return U.['G', 'E']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'e', 'n', 'a', 'b', 'l', 'e', '/', 'd', 'i', 's', 'a', 'b', 'l', 'e'] */
        void ['G', 'E'](bool fl) volatile { BIT_BAND_PER(U.U32, 1 << ['1', '6']) = fl; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        auto ['G', 'P', 'O', 'L']() const { return U.['G', 'P', 'O', 'L']; }
        /** @brief ['D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 't', 'y', 'p', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'n', ' ', 't', 'h', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'i', 'n', 'p', 'u', 't'] */
        void ['G', 'P', 'O', 'L'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        void ['G', 'P', 'O', 'L'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '7']); }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        auto ['G', 'N', 'B', 'R', 'E', 'Q']() const { return U.['G', 'N', 'B', 'R', 'E', 'Q']; }
        /** @brief ['N', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 't', 'o', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', ' ', 'D', 'e', 'f', 'i', 'n', 'e', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ',', ' ', 't', 'h', 'e', 'n', ' ', 's', 't', 'o', 'p', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'n', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'e', 'd', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', 's', ' ', 'i', 's', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '+', '1', '.', ' ', 'N', 'o', 't', 'e', ':', ' ', 'T', 'h', 'i', 's', ' ', 'f', 'i', 'e', 'l', 'd', ' ', 'c', 'a', 'n', ' ', 'o', 'n', 'l', 'y', ' ', 'b', 'e', ' ', 'w', 'r', 'i', 't', 't', 'e', 'n', ' ', 'w', 'h', 'e', 'n', ' ', 'G', 'E', ' ', 'b', 'i', 't', ' ', 'i', 's', ' ', 'r', 'e', 's', 'e', 't', '.'] */
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
        void ['G', 'N', 'B', 'R', 'E', 'Q'](uint32_t&& val) volatile { U.U32 = (U.U32 & ~['0', 'b', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0']) | (val << ['1', '9']); }
    };
    class alignas(4) ['R', 'G', 'S', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 's', 't', 'a', 't', 'u', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['O', 'F']: ['4']; // bitOffset ['0', ' ', 'T', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'f', 'l', 'a', 'g', ' ', 'T', 'h', 'e', ' ', 'f', 'l', 'a', 'g', ' ', 'i', 's', ' ', 's', 'e', 't', ' ', 'w', 'h', 'e', 'n', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'c', 'c', 'u', 'r', 's', ' ', 'o', 'n', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ',', ' ', 'w', 'h', 'i', 'l', 'e', ' ', 't', 'h', 'e', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'o', 'u', 'n', 't', 'e', 'r', ' ', 'v', 'a', 'l', 'u', 'e', ' ', 'i', 's', ' ', 'l', 'o', 'w', 'e', 'r', ' ', 't', 'h', 'a', 'n', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'l', 'a', 'g', ' ', 'i', 's', ' ', 'c', 'l', 'e', 'a', 'r', 'e', 'd', ' ', 'b', 'y', ' ', 'w', 'r', 'i', 't', 'i', 'n', 'g', ' ', '1', ' ', 't', 'o', ' ', 't', 'h', 'e', ' ', 'c', 'o', 'r', 'r', 'e', 's', 'p', 'o', 'n', 'd', 'i', 'n', 'g', ' ', 'C', 'O', 'F', 'x', ' ', 'b', 'i', 't', ' ', 'i', 'n', ' ', 'D', 'M', 'A', 'M', 'U', 'X', '_', 'R', 'G', 'C', 'F', 'R', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r', '.']
            };
            uint32_t U32;
        } U;
    public:
        auto U32() const { return U.U32; }
        /** @brief ['T', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'f', 'l', 'a', 'g', ' ', 'T', 'h', 'e', ' ', 'f', 'l', 'a', 'g', ' ', 'i', 's', ' ', 's', 'e', 't', ' ', 'w', 'h', 'e', 'n', ' ', 'a', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'c', 'c', 'u', 'r', 's', ' ', 'o', 'n', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ',', ' ', 'w', 'h', 'i', 'l', 'e', ' ', 't', 'h', 'e', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'o', 'u', 'n', 't', 'e', 'r', ' ', 'v', 'a', 'l', 'u', 'e', ' ', 'i', 's', ' ', 'l', 'o', 'w', 'e', 'r', ' ', 't', 'h', 'a', 'n', ' ', 'G', 'N', 'B', 'R', 'E', 'Q', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'l', 'a', 'g', ' ', 'i', 's', ' ', 'c', 'l', 'e', 'a', 'r', 'e', 'd', ' ', 'b', 'y', ' ', 'w', 'r', 'i', 't', 'i', 'n', 'g', ' ', '1', ' ', 't', 'o', ' ', 't', 'h', 'e', ' ', 'c', 'o', 'r', 'r', 'e', 's', 'p', 'o', 'n', 'd', 'i', 'n', 'g', ' ', 'C', 'O', 'F', 'x', ' ', 'b', 'i', 't', ' ', 'i', 'n', ' ', 'D', 'M', 'A', 'M', 'U', 'X', '_', 'R', 'G', 'C', 'F', 'R', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r', '.'] */
        auto ['O', 'F']() const { return BIT_BAND_PER(U.U32, 1 << ['0']); }
    };
    class alignas(4) ['R', 'G', 'C', 'F', 'R']_ { // ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'l', 'e', 'a', 'r', ' ', 'f', 'l', 'a', 'g', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r']
        union {
            struct {
            unsigned ['C', 'O', 'F']: ['4']; // bitOffset ['0', ' ', 'C', 'l', 'e', 'a', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'f', 'l', 'a', 'g', ' ', 'U', 'p', 'o', 'n', ' ', 's', 'e', 't', 't', 'i', 'n', 'g', ',', ' ', 't', 'h', 'i', 's', ' ', 'b', 'i', 't', ' ', 'c', 'l', 'e', 'a', 'r', 's', ' ', 't', 'h', 'e', ' ', 'c', 'o', 'r', 'r', 'e', 's', 'p', 'o', 'n', 'd', 'i', 'n', 'g', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'f', 'l', 'a', 'g', ' ', 'O', 'F', 'x', ' ', 'i', 'n', ' ', 't', 'h', 'e', ' ', 'D', 'M', 'A', 'M', 'U', 'X', '_', 'R', 'G', 'C', 'S', 'R', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r', '.']
            };
            uint32_t U32;
        } U;
    public:
        /** @brief ['C', 'l', 'e', 'a', 'r', ' ', 't', 'r', 'i', 'g', 'g', 'e', 'r', ' ', 'e', 'v', 'e', 'n', 't', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'f', 'l', 'a', 'g', ' ', 'U', 'p', 'o', 'n', ' ', 's', 'e', 't', 't', 'i', 'n', 'g', ',', ' ', 't', 'h', 'i', 's', ' ', 'b', 'i', 't', ' ', 'c', 'l', 'e', 'a', 'r', 's', ' ', 't', 'h', 'e', ' ', 'c', 'o', 'r', 'r', 'e', 's', 'p', 'o', 'n', 'd', 'i', 'n', 'g', ' ', 'o', 'v', 'e', 'r', 'r', 'u', 'n', ' ', 'f', 'l', 'a', 'g', ' ', 'O', 'F', 'x', ' ', 'i', 'n', ' ', 't', 'h', 'e', ' ', 'D', 'M', 'A', 'M', 'U', 'X', '_', 'R', 'G', 'C', 'S', 'R', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r', '.'] */
    };

    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '0', 'C', 'R']_ ['C', '0', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '1', 'C', 'R']_ ['C', '1', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '2', 'C', 'R']_ ['C', '2', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '3', 'C', 'R']_ ['C', '3', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '4', 'C', 'R']_ ['C', '4', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '5', 'C', 'R']_ ['C', '5', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '6', 'C', 'R']_ ['C', '6', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '7', 'C', 'R']_ ['C', '7', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '8', 'C', 'R']_ ['C', '8', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '9', 'C', 'R']_ ['C', '9', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '1', '0', 'C', 'R']_ ['C', '1', '0', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '1', '1', 'C', 'R']_ ['C', '1', '1', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '1', '2', 'C', 'R']_ ['C', '1', '2', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '1', '3', 'C', 'R']_ ['C', '1', '3', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '1', '4', 'C', 'R']_ ['C', '1', '4', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', '1', '5', 'C', 'R']_ ['C', '1', '5', 'C', 'R'];
    uint32_t padding64[16];
    /** @brief ['D', 'M', 'A', 'M', 'U', 'X', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 's', 't', 'a', 't', 'u', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'S', 'R']_ ['C', 'S', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'U', 'X', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'l', 'i', 'n', 'e', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', 'x', 'e', 'r', ' ', 'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't', ' ', 'c', 'l', 'e', 'a', 'r', ' ', 'f', 'l', 'a', 'g', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['C', 'F', 'R']_ ['C', 'F', 'R'];
    uint32_t padding136[30];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['R', 'G', '0', 'C', 'R']_ ['R', 'G', '0', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['R', 'G', '1', 'C', 'R']_ ['R', 'G', '1', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['R', 'G', '2', 'C', 'R']_ ['R', 'G', '2', 'C', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'h', 'a', 'n', 'n', 'e', 'l', ' ', 'x', ' ', 'c', 'o', 'n', 't', 'r', 'o', 'l', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['R', 'G', '3', 'C', 'R']_ ['R', 'G', '3', 'C', 'R'];
    uint32_t padding272[12];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 's', 't', 'a', 't', 'u', 's', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['R', 'G', 'S', 'R']_ ['R', 'G', 'S', 'R'];
    /** @brief ['D', 'M', 'A', 'M', 'u', 'x', ' ', '-', ' ', 'D', 'M', 'A', ' ', 'r', 'e', 'q', 'u', 'e', 's', 't', ' ', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'o', 'r', ' ', 'c', 'l', 'e', 'a', 'r', ' ', 'f', 'l', 'a', 'g', ' ', 'r', 'e', 'g', 'i', 's', 't', 'e', 'r'] */
    ['R', 'G', 'C', 'F', 'R']_ ['R', 'G', 'C', 'F', 'R'];
};

inline volatile ['D', 'M', 'A', 'M', 'U', 'X']_ _['D', 'M', 'A', 'M', 'U', 'X'] = *reinterpret_cast<['D', 'M', 'A', 'M', 'U', 'X']_*>(['0', 'x', '4', '0', '0', '2', '0', '8', '0', '0']);
