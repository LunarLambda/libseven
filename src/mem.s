.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

@ Memory Copy

func memCopy8 thumb
    bx          lr
endf

func memCopy16 thumb
    bx          lr
endf

func memCopy32 arm .iwram
    bx          lr
endf

@ Memory Move

func memMove8 thumb
    bx          lr
endf

func memMove16 thumb
    bx          lr
endf

func memMove32 arm .iwram
    bx          lr
endf

@ Memory Set

func memSet8 thumb
    bx          lr
endf

func memSet16 thumb
    bx          lr
endf

func memSet32 arm .iwram
    bx          lr
endf

@ Memory Zero

func memZero8 thumb
    movs        r2, r1
    movs        r1, #0
    b           memSet8
endf

func memZero16 thumb
    movs        r2, r1
    movs        r1, #0
    b           memSet16
endf

func memZero32 arm .iwram
    movs        r2, r1
    movs        r1, #0
    b           memSet32
endf

@ Memory Compare

func memCompare8 thumb
    bx          lr
endf

func memCompare16 thumb
    bx          lr
endf

func memCompare32 arm .iwram
    bx          lr
endf
