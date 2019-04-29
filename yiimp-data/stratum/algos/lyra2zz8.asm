
lyra2zz.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <lyra2zz_hash>:
   0:	4c 8d 54 24 08       	lea    r10,[rsp+0x8]
   5:	48 83 e4 c0          	and    rsp,0xffffffffffffffc0
   9:	41 ff 72 f8          	push   QWORD PTR [r10-0x8]
   d:	55                   	push   rbp
   e:	48 89 e5             	mov    rbp,rsp
  11:	41 55                	push   r13
  13:	4c 8d ad 40 ff ff ff 	lea    r13,[rbp-0xc0]
  1a:	41 54                	push   r12
  1c:	49 89 fc             	mov    r12,rdi
  1f:	bf 0e 00 00 00       	mov    edi,0xe
  24:	41 52                	push   r10
  26:	53                   	push   rbx
  27:	48 89 f3             	mov    rbx,rsi
  2a:	48 81 ec 10 01 00 00 	sub    rsp,0x110
  31:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  38:	00 00 
  3a:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
  3e:	31 c0                	xor    eax,eax
  40:	e8 00 00 00 00       	call   45 <lyra2zz_hash+0x45>
  45:	4c 89 ef             	mov    rdi,r13
  48:	e8 00 00 00 00       	call   4d <lyra2zz_hash+0x4d>
  4d:	ba 70 00 00 00       	mov    edx,0x70
  52:	4c 89 e6             	mov    rsi,r12
  55:	4c 89 ef             	mov    rdi,r13
  58:	e8 00 00 00 00       	call   5d <lyra2zz_hash+0x5d>
  5d:	4c 8d a5 d0 fe ff ff 	lea    r12,[rbp-0x130]
  64:	4c 89 ef             	mov    rdi,r13
  67:	4c 89 e6             	mov    rsi,r12
  6a:	e8 00 00 00 00       	call   6f <lyra2zz_hash+0x6f>
  6f:	48 83 ec 08          	sub    rsp,0x8
  73:	31 c0                	xor    eax,eax
  75:	4d 89 e0             	mov    r8,r12
  78:	6a 08                	push   0x8
  7a:	41 b9 20 00 00 00    	mov    r9d,0x20
  80:	b9 20 00 00 00       	mov    ecx,0x20
  85:	4c 89 e2             	mov    rdx,r12
  88:	6a 08                	push   0x8
  8a:	48 8d bd 10 ff ff ff 	lea    rdi,[rbp-0xf0]
  91:	be 20 00 00 00       	mov    esi,0x20
  96:	6a 08                	push   0x8
  98:	e8 00 00 00 00       	call   9d <lyra2zz_hash+0x9d>
  9d:	48 8b 85 10 ff ff ff 	mov    rax,QWORD PTR [rbp-0xf0]
  a4:	48 83 c4 20          	add    rsp,0x20
  a8:	48 89 03             	mov    QWORD PTR [rbx],rax
  ab:	48 8b 85 18 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe8]
  b2:	48 89 43 08          	mov    QWORD PTR [rbx+0x8],rax
  b6:	48 8b 85 20 ff ff ff 	mov    rax,QWORD PTR [rbp-0xe0]
  bd:	48 89 43 10          	mov    QWORD PTR [rbx+0x10],rax
  c1:	48 8b 85 28 ff ff ff 	mov    rax,QWORD PTR [rbp-0xd8]
  c8:	48 89 43 18          	mov    QWORD PTR [rbx+0x18],rax
  cc:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  d0:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
  d7:	00 00 
  d9:	75 11                	jne    ec <lyra2zz_hash+0xec>
  db:	48 8d 65 e0          	lea    rsp,[rbp-0x20]
  df:	5b                   	pop    rbx
  e0:	41 5a                	pop    r10
  e2:	41 5c                	pop    r12
  e4:	41 5d                	pop    r13
  e6:	5d                   	pop    rbp
  e7:	49 8d 62 f8          	lea    rsp,[r10-0x8]
  eb:	c3                   	ret    
  ec:	e8 00 00 00 00       	call   f1 <lyra2zz_hash+0xf1>
