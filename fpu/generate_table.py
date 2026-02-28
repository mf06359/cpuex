import os

# 入出力ファイル名
INPUT_FILE = "fsqrt_table.hex"
OUTPUT_FILE = "fsqrt_sq_table.hex"

def generate_sq_table():
    if not os.path.exists(INPUT_FILE):
        print(f"❌ エラー: '{INPUT_FILE}' が見つかりません。同じディレクトリに配置してください。")
        return

    try:
        with open(INPUT_FILE, 'r') as f_in, open(OUTPUT_FILE, 'w') as f_out:
            lines = f_in.readlines()
            
            for i, line in enumerate(lines):
                # 改行や空白を削除
                hex_str = line.strip()
                if not hex_str:
                    continue
                
                # 1. 16進数の文字列を整数 (24bit) に変換
                x_0 = int(hex_str, 16)
                
                # 2. x_0 の2乗を計算し、24ビット右シフト (SystemVerilogの >> 24 と同じ)
                x_0_sq = (x_0 * x_0) >> 24
                
                # 3. 24bit幅の16進数 (6桁) にフォーマットして書き込み
                # 06x は「小文字の16進数で、足りない上位桁を0埋めして6文字にする」という意味
                f_out.write(f"{x_0_sq:06x}\n")
                
        print(f"✅ 成功: '{OUTPUT_FILE}' を生成しました。({len(lines)} エントリ)")
        
    except Exception as e:
        print(f"❌ エラーが発生しました: {e}")

if __name__ == "__main__":
    generate_sq_table()
