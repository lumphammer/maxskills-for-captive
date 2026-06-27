/*
   Captive Name Generator
   Copyright (C) 2008 - Pierre Fournier
   =========================================================================

   In Captive, the name of a droid will also define its initial level of
   dexterity, vitality and wisdom.  This little application will generate
   droid names that start each of these skills at their maximum value of 15.

   Pierre "Lyverbe" Fournier - February 14, 2008

   =========================================================================
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "stdafx.h"
#include "resource.h"
#include "MaxSkillsDlg.h"

const char*    g_Consonant    = "BCDFGHJKLMNPQRTVWXZ";
const char*    g_Vowel        = "AEIOUY";

BEGIN_MESSAGE_MAP(CMaxSkillsDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_GENERATE, OnButtonGenerate)
END_MESSAGE_MAP()

CMaxSkillsDlg::CMaxSkillsDlg() :
	CDialog( IDD_MAXSKILLS_DIALOG )
{
   srand( time(NULL) );
}

//////////////////////////////////////////////////////////////////////////////
void CMaxSkillsDlg::OnButtonGenerate() 
{
   int Dexterity, Vitality, Wisdom;
   char Name[21];
   do
   {
      GenerateName( Name, sizeof(Name) );
      GetSkills( Name, Dexterity, Vitality, Wisdom );
   } while ( Dexterity != 15 || Vitality != 15 || Wisdom != 15 );

   SetDlgItemText( IDC_STATIC_NAME, Name );
}

//////////////////////////////////////////////////////////////////////////////
void CMaxSkillsDlg::GenerateName( char* pBuffer, int BufferSize )
{
   // The name can be anything made out of uppercase letters, numbers and
   // a couple of other characters.  To make it easier to read, we'll
   // build a name of syllables made of only a consonant and a vowel
   memset( pBuffer, 0, BufferSize );
   int NbrSyllables = 2 + (rand() % 4);
   for ( int SylID=1; SylID <= NbrSyllables; ++SylID )
   {
      char Syllable[2];
      sprintf( Syllable, "%c%c", g_Consonant[rand()%20], g_Vowel[rand()%6] );
      strcat( pBuffer, Syllable );
   }
}

//////////////////////////////////////////////////////////////////////////////
void CMaxSkillsDlg::GetSkills( const char* pName, int& Dexterity, int& Vitality, int& Wisdom )
{
   long d0 = 0;
   int CharID = 0;
   BYTE Char = !0;
   while ( Char != '\0' )
   {
      Char = pName[CharID++];
      d0 += Char;
      d0 *= 0x5e5;
      d0 += 0x29;
   }

   d0 *= 0x5e5;
   d0 += 0x29;
   long d1 = d0 & 0xffff;
   d1 *= 0x0d;
   d1 = ((d1 << 16) & 0xffff0000) | (d1 >> 16);
   d1 += 3;
   Dexterity = (d1 & 0x00ff);

   d0 *= 0x5e5;
   d0 += 0x29;
   d1 = d0 & 0xffff;
   d1 *= 0x0d;
   d1 = ((d1 << 16) & 0xffff0000) | (d1 >> 16);
   d1 += 3;
   Vitality = (d1 & 0x00ff);

   d0 *= 0x5e5;
   d0 += 0x29;
   d1 = d0 & 0xffff;
   d1 *= 0x0d;
   d1 = ((d1 << 16) & 0xffff0000) | (d1 >> 16);
   d1 += 3;
   Wisdom = (d1 & 0x00ff);
}
