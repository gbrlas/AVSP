/* Language used is Haxe (http://haxe.org/) compiled to C++ */

package;

import cpp.Lib;

class D {
	static function main() {
        var T = Std.parseInt(Sys.stdin().readLine());
        var i = 0, j = 0, k = 0, zz = 0;
        
        var start = new Array<Int>();
        var cur = new Array<Int>();
        for (i in 0...201) {
            start.push(0);
            cur.push(0);
        }
        
        var visible = new Array<Bool>();
        for (i in 0...(1 << 20)) visible.push(false);

        
        for (zz in 0...T) {
            var line = Sys.stdin().readLine().split(" ");
            var K = Std.parseInt(line[0]);
            var N = Std.parseInt(line[1]);
            
            line = Sys.stdin().readLine().split(" ");
            for (i in 0...201) start[i] = 0;
            for (i in 0...K) {
                k = Std.parseInt(line[i]);
                start[k]++;
            }
            
            var need = new Array<Int>();
            var gets = new Array<Map<Int, Int>>();
            for (i in 0...N) {
                line = Sys.stdin().readLine().split(" ");
                var t = Std.parseInt(line[0]);
                var l = Std.parseInt(line[1]);
                need.push(t);
                var m = new Map<Int, Int>();
                for (j in 0...l) {
                    k = Std.parseInt(line[2+j]);
                    m.set(k, m.get(k) == null ? 1 : m.get(k) + 1);
                }
                gets.push(m);
            }
            
            var adj = new Array<Array<Int>>();
            for (i in 0...(1 << N)) adj[i] = new Array<Int>();
            
            for (i in 0...(1 << N)) {
                for (i in 0...201) cur[i] = start[i];
                for (j in 0...N) if ((i & (1 << j)) != 0) {
                    cur[need[j]]--;
                    for (k in gets[j].keys())
                        cur[k] += gets[j].get(k);
                }
                
                for (j in 0...N) {
                    if (cur[need[j]] <= 0) continue;
                    adj[i | (1 << j)].push(i);
                }
            }
            
            for (i in 0...(1 << N)) visible[i] = false;
            
            var queue = new Array<Int>();
            visible[(1 << N) - 1] = true;
            queue.push((1 << N) - 1);
            
            while (queue.length > 0) {
                var next = queue.pop();
                for (i in 0...adj[next].length) {
                    if (visible[adj[next][i]]) continue;
                    visible[adj[next][i]] = true;
                    queue.push(adj[next][i]);
                }
            }
            
            if (!visible[0]) Sys.println('Case #${zz+1}: IMPOSSIBLE');
            else {
                var result = new Array<Int>();
                i = 0;
                while (i != (1 << N) - 1) {
                    for (i in 0...201) cur[i] = start[i];
                    for (j in 0...N) if ((i & (1 << j)) != 0) {
                        cur[need[j]]--;
                        for (k in gets[j].keys())
                            cur[k] += gets[j].get(k);
                    }
                    for (j in 0...N) {
                        var ni = i | (1 << j);
                        if (cur[need[j]] <= 0 || ni == i || !visible[ni]) continue;
                        result.push(j + 1);
                        i = ni;
                        break;
                    }
                }
                Sys.print('Case #${zz+1}:');
                for (i in result) Sys.print(' $i');
                Sys.println("");
            }
        }
	}
}