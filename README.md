# oF_threadTimer
simple thread timer example with openFrameworks


#
スレッドを利用したシンプルなタイマー
今後汎用的に使えるようにメモ。

メインスレッドで重たい処理があっても、setTimerした時間が来たらevent（サンプルではaction()）が動きます。

