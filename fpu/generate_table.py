import math

def generate_fsqrt_lut(filename="fsqrt_table.hex"):
    with open(filename, "w") as f:
        # 10bitアドレス (0 〜 1023 の 1024エントリ)
        for i in range(1024):
            # アドレスの最上位ビット [9]: 指数のLSB (e_1[0])
            e1_0 = (i >> 9) & 1
            
            # アドレスの下位9ビット [8:0]: 仮数部の上位9bit (m_1[22:14])
            m_bits = i & 0x1FF
            
            # 仮数部の計算
            # 0.5 を足すことで、各区間の「中央値」を狙い、丸め誤差を最小化します
            m_frac = (m_bits + 0.5) / 512.0
            M = 1.0 + m_frac
            
            # 指数の偶奇によってニュートン法の入力 x を切り替える
            if e1_0 == 1:
                # e_1[0] == 1 (元の指数が奇数 -> バイアスを引くと偶数)
                # x は 1.0 〜 2.0 の範囲 (SystemVerilog側の a_fixed = 1.M 相当)
                x = M
            else:
                # e_1[0] == 0 (元の指数が偶数 -> バイアスを引くと奇数)
                # x は 2.0 〜 4.0 の範囲 (SystemVerilog側の a_fixed = 2.M 相当)
                x = 2.0 * M
            
            # 逆数平方根 1/sqrt(x) の計算
            y0 = 1.0 / math.sqrt(x)
            
            # Q0.24 固定小数点フォーマットへ変換
            # 2^24 を掛けて四捨五入し、整数化する
            y0_fixed = int(round(y0 * (1 << 24)))
            
            # y0 が 1.0 の時 (x=1.0の時)、25bit (0x1000000) になってしまうのを防ぐため
            # 24bitの最大値 (0xFFFFFF) でクリップ（飽和）させる
            if y0_fixed > 0xFFFFFF:
                y0_fixed = 0xFFFFFF
                
            # 6桁の16進数 (24bit) としてファイルに書き込む
            f.write(f"{y0_fixed:06X}\n")

if __name__ == "__main__":
    generate_fsqrt_lut()
    print("fsqrt_table.hex を生成しました！")
