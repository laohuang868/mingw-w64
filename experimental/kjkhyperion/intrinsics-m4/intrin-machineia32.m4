divert(`-1')
INTRIN(`long',			`_InterlockedAddLargeStatistic',	((`__INTRIN_INT64 volatile *', `Addend'), (`long', `Value')))
INTRIN(`__m64',			`_m_from_float',			((`float', `f')))
INTRIN(`float',			`_m_to_float',				((`__m64', `m')))
INTRIN(`__m64',			`_mm_cvt_ps2pi',			((`__m128', `value')))
INTRIN(`__m64',			`_mm_cvtt_ps2pi',			((`__m128', `value')))
INTRIN(`__m128',		`_mm_cvt_pi2ps',			((`__m128', `a'), (`__m64', `b')))
INTRIN(`void',			`_mm_stream_pi',			((`__m64*', `p'), (`__m64', `a')))
INTRIN(`void',			`_m_femms')
INTRIN(`__m64',			`_m_pavgusb',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pf2id',				((`__m64', `m')))
INTRIN(`__m64',			`_m_pfacc',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfadd',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfcmpeq',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfcmpge',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfcmpgt',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfmax',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfmin',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfmul',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfrcp',				((`__m64', `m')))
INTRIN(`__m64',			`_m_pfrcpit1',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfrcpit2',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfrsqrt',				((`__m64', `m')))
INTRIN(`__m64',			`_m_pfrsqit1',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfsub',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfsubr',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pi2fd',				((`__m64', `m')))
INTRIN(`__m64',			`_m_pmulhrw',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pf2iw',				((`__m64', `m')))
INTRIN(`__m64',			`_m_pfnacc',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pfpnacc',				((`__m64', `m1'), (`__m64', `m2')))
INTRIN(`__m64',			`_m_pi2fw',				((`__m64', `m')))
INTRIN(`__m64',			`_m_pswapd',				((`__m64', `m')))
INTRIN(`unsigned long',		`__readcr0')
INTRIN(`unsigned long',		`__readcr2')
INTRIN(`unsigned long',		`__readcr3')
INTRIN(`unsigned long',		`__readcr4')
INTRIN(`unsigned long',		`__readcr8')
INTRIN(`void',			`__writecr0',				((`unsigned', `Data')))
INTRIN(`void',			`__writecr3',				((`unsigned', `Data')))
INTRIN(`void',			`__writecr4',				((`unsigned', `Data')))
INTRIN(`void',			`__writecr8',				((`unsigned', `Data')))
INTRIN(`unsigned',		`__readdr',				((`unsigned int', `DebugRegister')))
INTRIN(`void',			`__writedr',				((`unsigned int', `DebugRegister'), (`unsigned', `DebugValue')))
INTRIN(`unsigned',		`__readeflags')
INTRIN(`void',			`__writeeflags',			((`unsigned', `Value')))
INTRIN(`unsigned char',		`__readfsbyte',				((`unsigned long', `Offset')))
INTRIN(`unsigned short',	`__readfsword',				((`unsigned long', `Offset')))
INTRIN(`unsigned long',		`__readfsdword',			((`unsigned long', `Offset')))
INTRIN(`__INTRIN_UINT64',	`__readfsqword',			((`unsigned long', `Offset')))
INTRIN(`void',			`__writefsbyte',			((`unsigned long', `Offset'), (`unsigned char', `Data')))
INTRIN(`void',			`__writefsword',			((`unsigned long', `Offset'), (`unsigned short', `Data')))
INTRIN(`void',			`__writefsdword',			((`unsigned long', `Offset'), (`unsigned long', `Data')))
INTRIN(`void',			`__writefsqword',			((`unsigned long', `Offset'), (`__INTRIN_UINT64', `Data')))
divert`'dnl

