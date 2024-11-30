section .data
M_FACTOR dd 1000
S_FACTOR dd 3600

section .text
bits 64
default rel

global get_acceleration
get_acceleration:
    ; @param VI initial velocity [unit=km/h]
    ; @param VF final velocity at 1km [unit=km/h]
    ; @param T time to reach 1km [unit=s]
    ; @returns accel [unit=m/s^2]

    ; calculate (VF - VI)
    subss xmm1, xmm0 ; VF - VI

    ; convert km/h to m/s
    mulss xmm1, [M_FACTOR] ; km/h * 1000m/km
    divss xmm1, [S_FACTOR] ; m/h * 1h/3600s

    ; calculate DELTA V / T
    divss xmm1, xmm2 ; DELTA V / T

    ; convert to int and return
    cvtss2si eax, xmm1
    ret
