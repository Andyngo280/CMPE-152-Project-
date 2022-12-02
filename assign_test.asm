test			START	0
				LDA stackindex
				ADD #1762
				STA stackindex
				CLEAR X
				LDA #1759
				ADDR A,X
				LDA #0
				STA stack,X
				CLEAR X
				LDA #1756
				ADDR A,X
				LDA #1
				STA stack,X


				LDA stackindex
				ADD #3
				STA stackindex
				SUB #3
				CLEAR X
				ADDR A,X
				LDA #4
				STA stack,X
				LDA stackindex
				SUB #3
				STA stackindex
				CLEAR X
				ADDR A,X
				LDT stack,X
				LDA stackindex
				SUB #18
				CLEAR X
				ADDR A,X
				STT stack,X

				LDA stackindex
				ADD #3
				STA stackindex
				SUB #3
				CLEAR X
				ADDR A,X
				LDA #3
				STA stack,X
				LDA stackindex
				SUB #3
				STA stackindex
				CLEAR X
				ADDR A,X
				LDT stack,X
				LDA stackindex
				SUB #12
				CLEAR X
				ADDR A,X
				STT stack,X

				LDA #1762
				SUB #18
				CLEAR X
				ADDR A,X
				LDT stack,X
				LDA stackindex
				SUB #15
				CLEAR X
				ADDR A,X
				STT stack,X

				CLEAR X
				CLEAR T
				LDA #1747
				ADDR A,X
				LDT stack,X
stack			RESB 10000
stackindex		WORD 0
stackmax		WORD 10000
returnvalue		RESB 500
returnmax		WORD 500
				END  0
