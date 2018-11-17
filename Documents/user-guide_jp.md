## universal16ユーザーガイド
universal16は4x4のキーマトリクスとユニバーサル基板を組み合わせたもので、新しく自作キーボードで使いたい部品やコントローラーを用いた試作/実験に便利な基板です。
このユーザーガイドではどの配線がどのパッドに引き出してあるかなどの大まかな説明をしたものです。詳しくは各PCBが置いてある階層のREADMEをご確認ください。 <br>
universal16: [universal16-stem](../stem/README_jp.md) <br>
universal16+4: [universal16plus4](../plus4/README_jp.md)

|シルク印刷|説明|
|---|---|
|Rows|キースイッチマトリクスの'行'|
|Cols|キースイッチマトリクスの'列'|
|LEDRows|LEDマトリクスの'行'|
|LEDCols|LEDマトリクスの'列'|
|LED|UnderGlow用のLED信号線|
|PWR|電源電圧2種類/GND|
|VCC|5V/VCC/GNDなど|

シルク印刷のないパッドは特に配線がなく、隣り合った2つ同士で短絡しています。コントローラ/ユニバーサル基板間の配線としてご活用ください。

## サンプルコード/プロジェクト

sample以下にArduino等で使用可能なコードを置いています。<br>
随時追加/更新してまいります。

|プロジェクト名|説明|
|---|---|
|universal16|universal16でキーマトリクスを扱うサンプルコードです。<br>キーのpress/releaseをシリアルモニタに出力します。|
|keyaki_namiki \[WIP\]|universal16を使って左手デバイスをつくるプロジェクトです。<br>master/led_ctrlの2つのプログラムでArduinoを連携させ、ロータリーエンコーダやレイヤードキーマップなどの実装を目標としています。|