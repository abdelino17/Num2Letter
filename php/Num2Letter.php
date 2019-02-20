<?php

class Num2Letter
{
	function enter($userEnter)
	{
		$montant = trim($userEnter);
		$longueur = strlen($montant);
		$res ="";
		if($longueur >0 && $longueur <4)
		{
			$res = $this->Num2Let($montant);
		}else if($longueur >= 4 && $longueur < 7)
		{
			$res = $this->Mille2Letter($montant);
		}else if($longueur >=7 && $longueur < 10)
		{
			$res = $this->Millions2Letter($montant);
	
		}else if($longueur >=9 && $longueur <= 12)
		{
			$res = $this->Milliards2Letter($montant);
	
		}else
		{
			$res = "0";
		}
		
		return strtoupper($res);
	}
	
	
	public function Num2Let($number)
	{
		$units = ['','un','deux','trois','quatre','cinq','six','sept','huit','neuf','dix','onze','douze','treize','quartoze','quinze','seize','dix-sept','dix-huit','dix-neuf'];
	
		$tens = ['','dix','vingt','trente','quarante','cinquante','soixante','soixante','quatre-vingt','quatre-vingt'];
	
		$unit = $number%10;
		$ten = ($number%100 - $unit)/10;
		$hund = ($number%1000 -($number%100))/100;
	
		$unitOut = '';
		$tenOut = '';
		$hundOut = '';
		
		if($number === 0)
		{
			return 'zero';
		}else
		{
			$unitOut = ($unit === 1 && $ten>0 && $ten !== 8 ? 'et-' : '')."".$units[$unit];
			
			if($ten === 1 && $unit > 0)
			{
				$tenOut = $units[10 + $unit];
				$unitOut = '';
			}
			else if($ten === 7 || $ten === 9)
			{
				$tenOut = $tens[$ten] ."".'-'."". ($ten === 7 && $unit === 1 ? 'et-' : '' ) ."". $units[10 + $unit];
				$unitOut = '';
			}else
			{
				$tenOut = $tens[$ten];
			}
			$tenOut .= ($unit === 0 && $ten === 8 ? 's' : '');
			
			$hundOut = ($hund > 1 ? $units[$hund]."".'-':'')."".($hund > 0 ?'cent':'')."".(($hund>1 && $ten == 0 && $unit == 0)? 's' : '');
	
			return $hundOut ."". ($hundOut && $tenOut ? '-' : '') ."". $tenOut ."". ($hundOut && $unitOut || $tenOut && $unitOut ? '-' : '') ."". $unitOut;
		}
	}
	
	public function Mille2Letter($montant_str)
	{
		$sizeMille = strlen($montant_str);
		$end = substr($montant_str, -3);
		$deb = substr($montant_str, 0,$sizeMille-3);
	
		$debut = "";
		$fin = "";
	
		if((int)($deb) === 1)
		{
			$debut = " mille ";
		}else if((int)($deb) === 0)
		{
			$debut = "";
		}else
		{
			$debut = $this->Num2Let((int)($deb))." milles ";
		}
		if((int)($end) !== 0)
		{
			$fin = $this->Num2Let((int)($end));
		}
		return 	$debut." ".$fin;
	}
	
	public function Millions2Letter($montant_str)
	{
		$sizeMillions = strlen($montant_str);
		$end = substr($montant_str, -3);
		$middle =  substr($montant_str, -6, 3);
		$deb = substr($montant_str, 0,$sizeMillions-6);
	
		$debut = "";
		$fin = "";
	
		if((int)($deb)==1)
		{
			$debut = $this->Num2Let((int)($deb))." million ";
		}else if((int)($deb) == 0)
		{
			$debut = "";
		}else
		{
			$debut = $this->Num2Let((int)($deb))." millions ";
		}
		
		if((int)($end)==0 && (int)($middle)==0)
		{
			$fin = "";
		}else
		{
			$fin = $this->Mille2Letter($middle." ".$end);
		}
		return $debut." ".$fin;
	}
	
	public function Milliards2Letter($montant_str)
	{
		$sizeMillions = strlen($montant_str);
		$end = substr($montant_str, -3);
		$middle =  substr($montant_str, -6, 3);
		$deb2 =  substr($montant_str, -9, 3);
		$deb = substr($montant_str, 0, $sizeMillions-9);
	
		$debut = "";
		$fin = "";
	
		if((int)$deb === 1)
		{
			$debut = $this->Num2Let((int)($deb))." milliard ";
		}else if((int)($deb) == 0)
		{
			$debut = "";
		}else
		{
			$debut = $this->Num2Let((int)($deb))." milliards ";
		}
	
		if((int)($end)==0 && (int)($middle)==0 && (int)($deb2)==0)
		{
			$fin = "";
		}else
		{
			$fin = $this->Millions2Letter($deb2."".$middle."".$end);
		}
		return $debut." ".$fin;
	}
	
}


