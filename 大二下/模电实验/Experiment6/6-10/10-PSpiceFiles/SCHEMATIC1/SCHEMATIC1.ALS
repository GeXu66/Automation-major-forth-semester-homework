.ALIASES
R_R1            R1(1=0 2=N09801 ) CN @10.SCHEMATIC1(sch_1):INS9701@ANALOG.R.Normal(chips)
V_V4            V4(+=N09791 -=0 ) CN @10.SCHEMATIC1(sch_1):INS9757@SOURCE.VSIN.Normal(chips)
V_V3            V3(+=0 -=-15V ) CN @10.SCHEMATIC1(sch_1):INS9567@SOURCE.VDC.Normal(chips)
V_V2            V2(+=+15V -=0 ) CN @10.SCHEMATIC1(sch_1):INS9545@SOURCE.VDC.Normal(chips)
R_R2            R2(1=N09791 2=N09691 ) CN @10.SCHEMATIC1(sch_1):INS9721@ANALOG.R.Normal(chips)
X_U1            U1(+=N09801 -=N09691 V+=+15V V-=-15V OUT=N09697 ) CN @10.SCHEMATIC1(sch_1):INS9623@OPAMP.LM741.Normal(chips)
R_R3            R3(1=N09801 2=N09697 ) CN @10.SCHEMATIC1(sch_1):INS9848@ANALOG.R.Normal(chips)
R_R4            R4(1=N09697 2=N10120 ) CN @10.SCHEMATIC1(sch_1):INS9931@ANALOG.R.Normal(chips)
D_D1            D1(A=N112370 K=N10120 ) CN @10.SCHEMATIC1(sch_1):INS11227@DIODE.1N4684.Normal(chips)
D_D2            D2(A=N112370 K=0 ) CN @10.SCHEMATIC1(sch_1):INS11245@DIODE.1N4684.Normal(chips)
_    _(+15V=+15V)
_    _(-15V=-15V)
.ENDALIASES
