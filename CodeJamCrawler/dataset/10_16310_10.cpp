<pre>
<?php
class RC {
	public $R;
	public $k;
	public $N;
	public $queue = array();
	public $sum = 0;
	
	function __construct($R, $k, $N, $queueStr) {
		$this->queue = explode(' ', $queueStr);
		$this->R = $R;
		$this->k = $k;
		$this->N = $N;
		$this->ido();
	}
	
	function ido() {
		for($i = 0; $i < $this->R; $i++) {
			$this->glean();
		}
	}
	
	function glean() {
		$cnt = 0;
		foreach($this->queue as $key => $q) {
			if(($this->k - $cnt) >= intval($q)) {
				$this->sum += $q;
				$cnt += $q;
			} else {
				$this->queue = array_merge(array_slice($this->queue, $key), array_slice($this->queue, 0, $key));
				break;
			}
		}
	}
}

$handle = fopen("C-small-attempt0.in.txt", "r");
$handleW = fopen("output.txt", 'a');
$cnt = fgets($handle, 4096);

for($caseN=1; $caseN <= $cnt; $caseN++) {
    $buffer = fgets($handle, 4096);
    $buffer2 = fgets($handle, 4096);
	list($R, $k, $N) = explode(' ', $buffer);
	$rc = new RC($R, $k, $N, $buffer2);
	fwrite($handleW, "Case #$caseN: ".$rc->sum."\n");
}
fclose($handle);
fclose($handleW);
?>
</pre>