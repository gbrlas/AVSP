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
		my $N = &getToken();
		my $K = &getToken();
		my $mult = 2**$N;
		my $rem = ($K+1) % $mult;
		my $state = ($rem == 0)?'ON':'OFF';
		print "Case #$case: $state\n";
	}

}

&main();
