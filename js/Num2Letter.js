function Num2Let(number)
{
	var units = ['','un','deux','trois','quatre','cinq','six','sept','huit','neuf','dix','onze','douze','treize','quartoze','quinze','seize','dix-sept','dix-huit','dix-neuf'];
	
	var tens = ['','dix','vingt','trente','quarante','cinquante','soixante','soixante','quatre-vingt','quatre-vingt'];
	
	var unit = number%10;
	var ten = (number%100 - unit)/10;
	var hund = (number%1000 -(number%100))/100;
	
	var unitOut,tenOut,hundOut;
	
	if(number == 0)
	{
		return 'zero';
	}else
	{
		unitOut = (unit === 1 && ten>0 && ten !== 8 ? 'et-' : '') + units[unit];
	
		if(ten === 1 && unit > 0)
		{
			tenOut = units[10 + unit];
			unitOut ='';
		}
		else if(ten === 7 || ten === 9)
		{
			tenOut = tens[ten] +'-'+ (ten === 7 && unit === 1 ? 'et-' : '' ) + units[10 + unit]; 
			unitOut ='';
		}else
		{
			tenOut = tens[ten];
		}
		tenOut += (unit === 0 && ten === 8 ? 's' : '');
		
		hundOut = (hund > 1 ? units[hund] +'-' :'') + (hund > 0 ? 'cent' : '') + (hund>1 && ten == 0 && unit == 0 ? 's' : ''); 
		
		return hundOut + (hundOut && tenOut ? '-' : '') + tenOut + (hundOut && unitOut || tenOut && unitOut ? '-' : '') + unitOut;
	}
}

function Mille2Letter(montant_str)
{
	var sizeMille = montant_str.length;
	var end = montant_str.substring(sizeMille-3);
	var deb = montant_str.substring(0,sizeMille-3);

	var debut = "";
	var fin ="";

	if(parseInt(deb)==1)
	{
		debut = " mille ";
	}else if(parseInt(deb) == 0)
	{
		debut ="";
	}else
	{
		debut = Num2Let(parseInt(deb))+" milles ";  
	}	
	if(parseInt(end) != 0)
	{
		fin = Num2Let(parseInt(end));
	}
	return 	debut+" "+fin;
}	

function Millions2Letter(montant_str)
{
	var sizeMillions = montant_str.length;
	var end = montant_str.substring(sizeMillions-3);
	var middle =  montant_str.substring(sizeMillions-6,sizeMillions-3);
	var deb = montant_str.substring(0,sizeMillions-6);	

	var debut = "";
	var fin = "";

	if(parseInt(deb)==1)
	{
		debut = Num2Let(parseInt(deb))+" million ";
	}else if(parseInt(deb) == 0)
	{
		debut ="";
	}else
	{
		debut = Num2Let(parseInt(deb))+" millions ";
	}

	if(parseInt(end)==0 && parseInt(middle)==0)	
	{
		fin = "";
	}else
	{
		fin = Mille2Letter(middle+""+end);	
	}
	return debut+" "+fin;
}

function Milliards2Letter(montant_str)
{
	var sizeMillions = montant_str.length;
	var end = montant_str.substring(sizeMillions-3);
	var middle =  montant_str.substring(sizeMillions-6,sizeMillions-3);
	var deb2 =  montant_str.substring(sizeMillions-9,sizeMillions-6);
	var deb = montant_str.substring(0,sizeMillions-9);	

	var debut = "";
	var fin = "";

	if(parseInt(deb)==1)
	{
		debut = Num2Let(parseInt(deb))+" milliard ";
	}else if(parseInt(deb) == 0)
	{
		debut ="";
	}else
	{
		debut = Num2Let(parseInt(deb))+" milliards ";
	}

	if(parseInt(end)==0 && parseInt(middle)==0 && parseInt(deb2)==0)	
	{
		fin = "";
	}else
	{
		fin = Millions2Letter(deb2+""+middle+""+end);	
	}
	return debut+" "+fin;
}

function enter(userEnter)
{
	var montant = userEnter.trim();
	var longueur = montant.length;
	var res ="";
	if(longueur >0 && longueur <4)
	{
		res = Num2Let(montant);
	}else if(longueur >= 4 && longueur < 7)
	{
		res = Mille2Letter(montant);
	}else if(longueur >=7 && longueur < 10)
	{
		res = Millions2Letter(montant);

	}else if(longueur >=9 && longueur < 12)
	{
		res = Milliards2Letter(montant);

	}else
	{
		res = "0";
	}
	res = res+" ";
	return res.toUpperCase();
} 