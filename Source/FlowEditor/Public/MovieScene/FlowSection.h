// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "ISequencerSection.h"
#include "ISequencer.h"

class FSequencerSectionPainter;

class FLOWEDITOR_API FFlowSectionBase : public FSequencerSection
{
public:
	FFlowSectionBase(UMovieSceneSection& InSectionObject, TWeakPtr<ISequencer> InSequencer)
		: FSequencerSection(InSectionObject)
		, Sequencer(InSequencer)
	{
	}

protected:
	void PaintEventName(FSequencerSectionPainter& Painter, int32 LayerId, const FString& EventString, float PixelPosition, bool bIsEventValid = true) const;
	bool IsSectionSelected() const;

	TWeakPtr<ISequencer> Sequencer;
};

/**
* An implementation of flow sections.
*/
class FLOWEDITOR_API FFlowSection : public FFlowSectionBase
{
public:
	FFlowSection(UMovieSceneSection& InSectionObject, TWeakPtr<ISequencer> InSequencer)
		: FFlowSectionBase(InSectionObject, InSequencer)
	{
	}

	virtual int32 OnPaintSection(FSequencerSectionPainter& Painter) const override;
};

class FLOWEDITOR_API FFlowTriggerSection : public FFlowSectionBase
{
public:
	FFlowTriggerSection(UMovieSceneSection& InSectionObject, TWeakPtr<ISequencer> InSequencer)
		: FFlowSectionBase(InSectionObject, InSequencer)
	{
	}

	virtual int32 OnPaintSection(FSequencerSectionPainter& Painter) const override;
};

class FLOWEDITOR_API FFlowRepeaterSection : public FFlowSectionBase
{
public:
	FFlowRepeaterSection(UMovieSceneSection& InSectionObject, TWeakPtr<ISequencer> InSequencer)
		: FFlowSectionBase(InSectionObject, InSequencer)
	{
	}

	virtual int32 OnPaintSection(FSequencerSectionPainter& Painter) const override;
};
