	.align 2
gCryTable::
.if P_CRIES_ENABLED == TRUE
	cry Cry_Namazu
.endif @ P_CRIES_ENABLED

	.align 2
gCryTable_Reverse::
.if P_CRIES_ENABLED == TRUE
	cry_reverse Cry_Namazu
.endif @ P_CRIES_ENABLED
