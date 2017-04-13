my @tokens = ();

sub getToken {
	my $num = scalar @tokens;
	if ($num == 0){
		my $line = <STDIN>;
		chomp $line;
		@tokens = split(/ /,$line);
	}
	return shift @tokens;
}


sub main {
	my $T = &getToken();
	foreach my $case (1..$T){
		my $R = &getToken();
		my $k = &getToken();
		my $N = &getToken();
		my @groups = ();
		foreach (1..$N){
			push(@groups,&getToken());
		}
		my $earnings = 0;
		foreach my $round (1..$R){
			my $ppl = 0;
			my @onboard  = ();
			while(@groups){
				my $g = shift(@groups);
				if(($ppl+$g) > $k){
								unshift(@groups,$g);
								last;
				}
				$ppl += $g ;
				push(@onboard,$g);
			} 
			push(@groups,@onboard);

			$earnings += $ppl;
		}
		print "Case #$case: $earnings\n";
	}

}

&main();

