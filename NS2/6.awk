BEGIN {
	sSize=0;
	startTime = 5.0;
	stopTime = 0.1;
	Tput = 0;
}
{
	event = $1;
	time = $2;
	size = $6;
	
	if (event == "+") 
	{
		if(time < startTime) 
		{
			startTime = time;
		}
	}
	if (event == "r") 
	{
		if(time > stopTime) 
		{
			stopTime = time;
		}
		sSize+=size;
	}
	Tput = (sSize/(stopTime-startTime))*(8/1000);
	printf("%f \t %.2f \n",time,Tput);
}
END {
}
